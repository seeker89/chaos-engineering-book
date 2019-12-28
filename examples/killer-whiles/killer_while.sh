# restart instance A 5 times, spaced out by 1.5 second delays
i="0"
while [ $i -lt 4 ]
do
    echo "Restarting faas001_a $ith time"
    systemctl restart faas001_a
    sleep 1.5
    i=$[$i+1]
done

# restart instance B 5 times, spaced out by 1.5 second delays
i="0"
while [ $i -lt 4 ]
do
    echo "Restarting faas001_b $ith time"
    systemctl restart faas001_b
    sleep 1.5
    i=$[$i+1]
done
