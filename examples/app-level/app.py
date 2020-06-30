import uuid
import json
import redis
import flask

COOKIE_NAME = "sessionID"

def get_session_id():
    """ Read session id from cookies, if present """
    return flask.request.cookies.get(COOKIE_NAME)

def set_session_id(response, override=False):
    """ Store session id in a cookie """
    session_id = get_session_id()
    if not session_id or override:
        session_id = uuid.uuid4()
    session_id = response.set_cookie(COOKIE_NAME, str(session_id))


CACHE_CLIENT = redis.Redis(host="localhost", port=6379, db=0)

def get_interests(session):
    """ Retrieve interests stored in the cache for the session id """
    return json.loads(CACHE_CLIENT.get(session) or "[]")

def store_interests(session, query):
    """ Store user interest in the cache backend """
    stored = get_interests(session)
    if query and query not in stored:
        stored.append(query)
    CACHE_CLIENT.set(session, json.dumps(stored))
    return stored


def recommend_other_products(query, interests):
    """ Return a list of recommended products for a user, based on interests """
    return {"this amazing product": "https://youtube.com/watch?v=dQw4w9WgXcQ"}


app = flask.Flask(__name__)
@app.route("/")
def index():
    """ Handle the home page, search form """
    resp = flask.make_response("""
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
    query = flask.request.form.get("query")
    session_id = get_session_id()
    new_interests = store_interests(session_id, query)
    kwargs = dict(
        query=query,
        session_id=session_id,
        new_interests=new_interests,
        recommendations=recommend_other_products(query, new_interests),
    )
    resp = flask.make_response(flask.render_template_string("""
    <html><body>
        <p><h3>Hmmm...</h3></p>
        {% if query %}<p>I didn't find any "{{ query }}".</p>{% endif %}
        <p>Since you're interested in {{ new_interests }}, why don't you try...
        {% for k, v in recommendations.items() %} <a href="{{ v }}">{{ k }}</a>{% endfor %}!</p>
        <p>Session ID: {{ session_id }}. <a href="/">Go back.</a></p>
    </body></html>
    """, **kwargs))
    return resp

@app.route("/reset")
def reset():
    """ Reset the session ID cookie """
    resp = flask.make_response(flask.redirect("/"))
    set_session_id(resp, override=True)
    return resp
