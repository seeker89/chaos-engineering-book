#! /usr/bin/env python3

# Ha! If only generating legacy was this simple!

BUZZWORDS = sorted([
    "pivot",
    "ai",
    "disrupt",
    "deep_dive",
    "growth_hacking",
    "agile",
    "unicorn",
    "crypto",
    "previous_legacy",
    "next_gen",
    "big_data",
])

LINE_ENDING = "\r\n"
EMBED = """<!doctype html><html><head><title>Rickroll!</title></head><body><iframe width="560" height="315" src="https://www.youtube-nocookie.com/embed/dQw4w9WgXcQ" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe></body></html>"""

FUNC_TEMPLATE = """
#include <unistd.h>
#include "{next_name}.h"

ssize_t {name}(int fd) {{
    int a = {val1}, {name}_b = {val2}, {name}_{name} = {val3};
    for (int i = 0; i < {offset}; i++){{
        a--; {name}_b--;
    }}
    // not sure why, this didn't work with --
    // TODO check why it wasn't working 
    {name}_{name} += -1 * {offset};
    write(fd, &a, sizeof(a));
    write(fd, &{name}_b, sizeof(a)); // maybe should be {name}_b? It wouldn't compile
    write(fd, &{name}_{name}, sizeof({name}_{name}));
    // TODO prevent stack overflow
    {next_call};
    return 0; // TODO return something more meaningful
}}
"""

HEADER_TEMPLATE = """
#include <unistd.h>

ssize_t {name}(int);
"""

def generate_func(name, next_name, embed_offset):
    offset = 3
    substring = EMBED[embed_offset:embed_offset+3]
    header = HEADER_TEMPLATE.format(
        name=name,
    )
    body = FUNC_TEMPLATE.format(
        name=name,
        next_name=next_name if next_name else name,
        offset=offset,
        next_call="{}(fd)".format(next_name) if next_name else "",
        val1=ord(substring[0]) - offset,
        val2=ord(substring[1]) - offset,
        val3=ord(substring[2]) - offset,
    )
    return header, body, substring

print(generate_func(BUZZWORDS[0], BUZZWORDS[1], 0))