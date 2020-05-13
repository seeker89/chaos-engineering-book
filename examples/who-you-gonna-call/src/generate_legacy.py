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
EMBED = """<!doctype html><html><head><title>Rickroll!</title></head><body><iframe width="560" height="315" src="https://www.youtube-nocookie.com/embed/dQw4w9WgXcQ" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe></body></html>   """

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
    int size = 5;
    write(fd, &size, sizeof(size));
    char newline[] = "\\r\\n";
    write(fd, newline, sizeof(newline)-1);
    write(fd, &a, sizeof(a));
    write(fd, &{name}_b, sizeof(a)); // maybe should be {name}_b? It wouldn't compile
    write(fd, &{name}_{name}, sizeof({name}_{name}));
    write(fd, newline, sizeof(newline)-1);
    // TODO prevent stack overflow
    {next_call};
    return 0; // TODO return something more meaningful
}}
"""

HEADER_TEMPLATE = """
#include <unistd.h>

ssize_t {name}(int);
"""

WRITER_TEMPLATE = """
#include <unistd.h>
#include "{name}.h"

ssize_t write_content(int fd){{
    // Not sure what else should go here, but here's for nothing
    {name}(fd);
    // TODO return something useful
    // TODO error handling
    return 0;
}}
"""

def generate_func(name, next_name, content, content_offset):
    offset = 3
    substring = content[content_offset:content_offset+3]
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
    return header, body


def generate_all(names, content):
    offset = 0
    index = 0
    next_index = 1
    generation = 0
    next_name = ""
    while offset + 6 < len(content):
        name = "{}_{}".format(names[index], generation)
        next_index += 1
        if next_index >= len(names):
            generation += 1
            next_index = 0
        next_name = "{}_{}".format(names[next_index], generation)
        # plug into the system
        if index == 0 and generation == 0:
            with open("writer.c", "w") as f:
                f.write(WRITER_TEMPLATE.format(
                    name=name,
                ))
        header, body = generate_func(name, next_name, content, offset)
        with open("{}.h".format(name), "w") as f:
            f.write(header)
        with open("{}.c".format(name), "w") as f:
            f.write(body)
        index = next_index
        offset += 3
    # handle the last one
    header, body = generate_func(next_name, None, content, offset)
    with open("{}.h".format(next_name), "w") as f:
        f.write(header)
    with open("{}.c".format(next_name), "w") as f:
        f.write(body)

generate_all(BUZZWORDS, EMBED)
