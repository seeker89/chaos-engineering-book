#!/bin/bash

# A comic-book-villain-style killing
while :
do
  date
  kubectl get pods -l app=goldpinger -o name \
    | sort --random-sort \
    | head -n 1 \
    | xargs kubectl delete
  sleep 10
done
