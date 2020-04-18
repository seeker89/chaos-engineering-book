#!/bin/bash

# print the command
set -o xtrace

# run the benchmark
ab -t 30 -c 10 -l http://127.0.0.1:8003/api/v1/
