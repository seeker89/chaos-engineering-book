#! /bin/bash
FILESIZE=$((100*1024*1024))
FILENAME=testfile
echo "Press [CTRL+C] to stop.."
count=0
while :
do
    new_name=$FILENAME.$count
    fallocate -l $FILESIZE $new_name && echo "OK wrote the file" `ls -alhi $new_name` || echo "Couldn't write the file" $new_name
    sleep 1
    (( count++ ))
done
