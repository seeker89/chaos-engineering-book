#! /bin/bash

pumba netem \
    --duration 60s \
    --tc-image gaiadocker/iproute2 \
    delay \
        --time 100 \
        --jitter 0 \
        --correlation 0 \
        "re2:meower_db"
