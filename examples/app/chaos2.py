import os
import redis


def raise_rediserror_every_other_time_if_enabled(func):
    """ Decorator, raises an exception every other call to the wrapped function """
    if not os.environ.get("CHAOS"):
        return func
    counter = 0
    def wrapped(*args, **kwargs):
        nonlocal counter
        counter += 1
        if counter % 2 == 0:
            raise redis.exceptions.RedisError("CHAOS")
        return func(*args, **kwargs)
    return wrapped
