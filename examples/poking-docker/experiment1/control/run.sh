#! /bin/bash
FILESIZE=$((50*1024*1024))
FILENAME=testfile
while :
do
	echo "Press [CTRL+C] to stop.."
    fallocate -l $FILESIZE $FILENAME && echo "Wrote the file" || "Couldn't write the file"
	sleep 2
done
