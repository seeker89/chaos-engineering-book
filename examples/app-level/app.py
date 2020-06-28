import uuid
import json
import redis
from flask import Flask, request, make_response, render_template_string

COOKIE_NAME = "sessionID"

def get_session_id():
    return request.cookies.get(COOKIE_NAME)

def set_session_id(response):
    session_id = uuid.uuid4()
    session_id = response.set_cookie(COOKIE_NAME, str(session_id))


redis_client = redis.Redis(host="localhost", port=6379, db=0)
def get_interests(session):
    return json.loads(redis_client.get(session) or "[]")

def store_interests(session, query):
    stored = get_interests(session)
    if query not in stored:
        stored.append(query)
    redis_client.set(session, json.dumps(stored))
    return stored


app = Flask(__name__)
@app.route("/")
def index():
    session_id = get_session_id()
    resp = make_response("""
    <html><body>
        <form action="/search" method="POST">
            <p><h3>What would you like to buy today?</h3></p>
            <p><input type='text' name='query'/>
            <input type='submit' value='Search'/></p>
        </form>
    </body></html>
    """)
    if not session_id:
        set_session_id(resp)
    return resp

@app.route("/search", methods=["POST"])
def search():
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
        <p>I didn't find any "{{ query }}".</p>
        <p>But since you're interested in {{ new_interests }}, why don't you try...
        <a href="https://youtube.com/watch?v=dQw4w9WgXcQ">this</a></p>
        <p>Session ID: {{ session_id }}. <a href="/">Go back.</a></p>
    </body></html>
    """, **kwargs))
    return resp