#!/bin/bash

echo "Listing backend services"
ps auxf | grep killer-whiles | grep python
echo

echo "Killing instance A (port 8001)"
ps auxf | grep python | grep 8001 | awk '{system("sudo kill " $2)}'
sleep 0.5
systemctl status faas001_a --no-pager
echo

echo "Wait some time in-between killings"
sleep 2
echo

echo "Killing instance B (port 8002)"
ps auxf | grep python | grep 8002 | awk '{system("sudo kill " $2)}'
sleep 0.5
systemctl status faas001_b --no-pager
echo

echo "Listing backend services"
ps auxf | grep killer-whiles | grep python
echo "Done here!"
