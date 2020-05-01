#! /bin/bash
CONTAINER_PID=$(docker inspect -f '{{ .State.Pid }}' experiment2)
sudo nsenter \
    --pid \
    --target $CONTAINER_PID \
    /bin/bash /home/chaos/src/examples/poking-docker/experiment2/pid-printer.sh
