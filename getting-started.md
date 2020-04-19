# Getting started

## TL;DR

- [Install VirtualBox](https://www.virtualbox.org/wiki/Downloads)
- Download [the lastest release of the VM image](https://github.com/seeker89/chaos-engineering-in-action/releases) to a location of your choice (make sure the files are all in the same directory)
- Unzip the downloaded files
  - MacOS/Linux
    - (optional) Confirm checksums of downloaded parts with `shasum -a 256 -c parts.sha256`
    - Concatenate the parts into a single archive `cat chaos-engineering-VM*.z* > vm.zip`
    - Unzip it `unzip vm.zip`
    - Confirm the resulting VM image is intact `shasum -a 256 -c chaos-engineering-VM.sha256`
  - Windows
    - Confirm the checksums. On Windows 10, you should be able to run `CertUtil -hashfile PATH_TO/parts.sha256 SHA256`. Or use [Cygwin](http://www.cygwin.com/).
    - Unzip the `.zip` file - your zip program (like 7-zip) should automatically find all files
    - Confirm the resulting VM image is intact `chaos-engineering-VM.sha256`
  - There should be two files in a new subfolder: a `.ovf` and `.vmdk` one
- Import the VM image into VirtualBox:
  - In VirtualBox, click `File -> Import Appliance`
  - Pick the VM image file (the `.ovf` file) you downloaded and unzipped
  - Follow the wizard until completion
  - Start the VM and log in. The username and password are both `chaos`


## Configuration

There is plenty of options you might want to tweak to fit your setup. Some of the recommended ones:

- Configure sane defaults for the VM:
  - Right click your new VM and choose settings
  - In `General -> Advanced -> Shared Clipboard` check `Bidirectional` (default)
  - In `System -> Motherboard` choose `4096 MB` of `Base Memory` (default)
  - In `Display -> Video Memory` choose at least 64MB (default)
  - In `Display -> Remote Display` uncheck `Enable Server`
  - In `Display -> Graphics Controller` choose what best suits your host OS
