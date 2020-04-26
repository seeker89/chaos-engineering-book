#! /bin/bash
FILESIZE=$((50*1024*1024))
FILENAME=testfile
echo "Press [CTRL+C] to stop.."
while :
do
    fallocate -l $FILESIZE $FILENAME && echo "OK wrote the file" `date` || "Couldn't write the file"
	sleep 2
done
