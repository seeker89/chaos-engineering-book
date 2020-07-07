import os
import redis


def raise_rediserror_every_other_time(func):
    """ Decorator, raises an exception every other call to the wrapped function """
    if os.environ.get("CHAOS") != "true":
        return func
    counter = 0
    def wrapped():
        counter += 1
        if counter % 2 == 0:
            raise redis.exceptions.RedisError("CHAOS")
        return func()
    return wrapped
