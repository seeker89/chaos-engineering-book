# restart instance A a few times, spaced out by 1.5 second delays
i="0"
while [ $i -le 5 ]
do
    echo "Killing faas001_a ${i}th time"
    ps auxf | grep killer-whiles | grep python | grep 8001 | awk '{system("sudo kill " $2)}'
    sleep 1.25
    i=$[$i+1]
done

systemctl status faas001_a --no-pager

# restart instance B a few times, spaced out by 1.5 second delays
i="0"
while [ $i -le 5 ]
do
    echo "Killing faas001_b ${i}th time"
    ps auxf | grep killer-whiles | grep python | grep 8002 | awk '{system("sudo kill " $2)}'
    sleep 1.25
    i=$[$i+1]
done

systemctl status faas001_b --no-pager

echo "Waiting 10 seconds"
sleep 10

systemctl status faas001_a --no-pager
systemctl status faas001_b --no-pager
