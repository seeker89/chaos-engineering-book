#! /usr/bin/env python3

import os

# Ha! If only generating legacy was this simple!

BUZZWORDS = sorted([
    "pivot",
    "ai",
    "disrupt",
    "deep_dive",
    "agile",
    "unicorn",
    "crypto",
    "previous_legacy",
    "next_gen",
    "big_data",
    "machine_learning",
    "web_scale",
    "accelerator",
    "data_mining",
    "map_reduce",
    "fission",
    "preprocessing",
    "networking",
    "cloud",
    "enterprise_ready",
    "grpc",
    "new_4g",
    "organic",
    "free_range",
    "saas",
    "iaas",
    "paas",
    "internet_of_things",
    "private_cloud",
    "microservices",
    "monolith",
    "container",
    "virtualization",
    "simulation",
    "emulator",
    "bleeding_edge",
    "blockchain",
    "scalability",
    "lean",
    "abandonware"
])

EMBED = """<!doctype html><html><head><title>Rickroll!</title></head><body><iframe width="560" height="315" src="https://www.youtube-nocookie.com/embed/dQw4w9WgXcQ" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe></body></html>   """

FUNC_TEMPLATE = """
#include "../respond.h"
#include "{next_name}.h"
#include <errno.h>

ssize_t {name}(int fd) {{
    char a = {val1}, {name}_b = {val2}, {name}_{name} = {val3};
    for (int i = 0; i < {offset}; i++){{
        a++; {name}_b++;
    }}
    // not sure why, this didn't work with ++
    // TODO check why it wasn't working 
    {name}_{name} -= {offset} * -1;
    char size = '3';
    // migration to retire the content-type: chunked
    // migration status: 90%
    //respond(fd, &size, sizeof(size));
    //char newline[] = "\\r\\n";
    //respond(fd, newline, sizeof(newline)-1);
    respond(fd, &a, sizeof(a));
    respond(fd, &{name}_b, sizeof(a)); // maybe should be {name}_b? It wouldn't compile
    ssize_t r = respond(fd, &{name}_{name}, sizeof({name}_{name}));
    //respond(fd, newline, sizeof(newline)-1);
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

WRITER_HEADER_TEMPLATE = """
#include <unistd.h>
#define CTN_LENGTH "{len}"

ssize_t write_content(int);
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
        next_call="if (r >= 0 || errno != EPIPE) {}(fd);".format(next_name) if next_name else "",
        val1=ord(substring[0]) - offset,
        val2=ord(substring[1]) - offset,
        val3=ord(substring[2]) - offset,
    )
    return header, body


def generate_all(names, content):
    os.makedirs("./legacy",exist_ok=True)
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
            with open("./legacy/writer.c", "w") as f:
                f.write(WRITER_TEMPLATE.format(
                    name=name,
                    len=len(content),
                ))
            with open("./legacy/writer.h", "w") as f:
                f.write(WRITER_HEADER_TEMPLATE.format(
                    len=len(content) //3 *3,
                ))
        header, body = generate_func(name, next_name, content, offset)
        with open("./legacy/{}.h".format(name), "w") as f:
            f.write(header)
        with open("./legacy/{}.c".format(name), "w") as f:
            f.write(body)
        index = next_index
        offset += 3
    # handle the last one
    header, body = generate_func(next_name, None, content, offset)
    with open("./legacy/{}.h".format(next_name), "w") as f:
        f.write(header)
    with open("./legacy/{}.c".format(next_name), "w") as f:
        f.write(body)

generate_all(BUZZWORDS, EMBED)
