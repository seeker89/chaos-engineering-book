echo "Listing backend services"
ps auxf | grep killer-whiles | grep python
sleep 1
echo

echo "Killing instance A (port 8001)"
ps auxf | grep killer-whiles | grep python | grep 8001 | awk '{system("sudo kill " $2)}'
sleep 1
systemctl status faas001_a
sleep 1
echo

echo "Killing instance A (port 8002)"
ps auxf | grep killer-whiles | grep python | grep 8002 | awk '{system("sudo kill " $2)}'
sleep 1
systemctl status faas001_b
sleep 1
echo

echo "Listing backend services"
ps auxf | grep killer-whiles | grep python
echo "Done here!"
