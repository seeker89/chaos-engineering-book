# restart instance A 5 times, spaced out by 1.5 second delays
i="0"
while [ $i -le 4 ]
do
    echo "Restarting faas001_a ${i}th time"
    ps auxf | grep killer-whiles | grep python | grep 8001 | awk '{system("sudo kill " $2)}'
    sleep 1.5
    i=$[$i+1]
done

systemctl status faas001_a

# restart instance B 5 times, spaced out by 1.5 second delays
i="0"
while [ $i -le 4 ]
do
    echo "Restarting faas001_b ${i}th time"
    ps auxf | grep killer-whiles | grep python | grep 8002 | awk '{system("sudo kill " $2)}'
    sleep 1.5
    i=$[$i+1]
done

systemctl status faas001_b
