# Getting started

## TL;DR

- [Install VirtualBox](https://www.virtualbox.org/wiki/Downloads)
- Download the image files to a location of your choice
- Import the VM image into VirtualBox:
  - In VirtualBox, click `File -> Import Appliance`
  - Pick the VM image file you downloaded
  - Follow the wizard until completion
- Configure sane defaults for the VM:
  - Right click your new VM and choose settings
  - In `General -> Advanced -> Shared Clipboard` check `Bidirectional`
  - In `System -> Motherboard` choose `4096 MB` of `Base Memory`
  - In `Display -> Video Memory` choose at least 64MB
  - In `Display -> Remote Display` uncheck `Enable Server`
- Start the VM and log in. The username and password are both `chaos`
