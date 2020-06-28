import uuid
import json
import redis
from flask import Flask, request, redirect, make_response, render_template_string

COOKIE_NAME = "sessionID"

def get_session_id():
    return request.cookies.get(COOKIE_NAME)

def set_session_id(response, override=False):
    session_id = get_session_id()
    if not session_id or override:
        session_id = uuid.uuid4()
    session_id = response.set_cookie(COOKIE_NAME, str(session_id))


redis_client = redis.Redis(host="localhost", port=6379, db=0)
def get_interests(session):
    return json.loads(redis_client.get(session) or "[]")

def store_interests(session, query):
    stored = get_interests(session)
    if query and query not in stored:
        stored.append(query)
    redis_client.set(session, json.dumps(stored))
    return stored


app = Flask(__name__)
@app.route("/")
def index():
    """ Home page, search form """
    resp = make_response("""
    <html><body>
        <form action="/search" method="POST">
            <p><h3>What would you like to buy today?</h3></p>
            <p><input type='text' name='query'/>
            <input type='submit' value='Search'/></p>
        </form>
        <p><a href="/search">Recommendations</a>. <a href="/reset">Reset</a>. </p>
    </body></html>
    """)
    set_session_id(resp)
    return resp

@app.route("/search", methods=["POST", "GET"])
def search():
    """ Handle search, suggest other products """
    query = request.form.get("query")
    session_id = get_session_id()
    new_interests = store_interests(session_id, query)
    kwargs = dict(
        query=query,
        session_id=session_id,
        new_interests=new_interests,
    )
    resp = make_response(render_template_string("""
    <html><body>
        <p><h3>Hmmm...</h3></p>
        {% if query %}<p>I didn't find any "{{ query }}".</p>{% endif %}
        <p>Since you're interested in {{ new_interests }}, why don't you try...
        <a href="https://youtube.com/watch?v=dQw4w9WgXcQ">this amazing product</a>!</p>
        <p>Session ID: {{ session_id }}. <a href="/">Go back.</a></p>
    </body></html>
    """, **kwargs))
    return resp

@app.route("/reset")
def reset():
    """ Resets the session ID cookie """
    resp = make_response(redirect("/"))
    set_session_id(resp, override=True)
    return resp
