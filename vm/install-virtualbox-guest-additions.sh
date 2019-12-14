#!/bin/bash

mkdir /tmp/additions
sudo mount -t iso9660 -o loop /home/chaos/VBoxGuestAdditions.iso /tmp/additions
sudo /tmp/additions/VBoxLinuxAdditions.run
sudo umount /tmp/additions
rm -rf /tmp/additions /home/chaos/VBoxGuestAdditions.iso
