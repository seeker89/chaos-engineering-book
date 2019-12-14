# Setting up the VM

The code in this book has been designed so that it's easy to follow using this VM.
The easiest way to get started is to use the prebuild image available from releases. You can download it and launch in VirtualBox directly.


## Building from scratch

If you'd like to build the VM from scratch, please follow these steps.

### Prerequisites

- `packer` (tested on version 1.4.3) - [installation instructions](https://www.packer.io/docs/install/index.html)
- `virtualbox` (tested on versino 6.0.14) [installation instructions](https://www.virtualbox.org/wiki/Downloads)
- `ansible` (tested on version 2.8.4) - [installation instructions](https://docs.ansible.com/ansible/latest/installation_guide/intro_installation.html)

### Building a machine

`Makefile` contains all [instructions for packer](./packer.json) to:
- download an iso image of Ubuntu bionic and validate the checksums
- start a new VirtualBox machine with the iso
- install the OS
- run ansible playbook to install all the things necessary for following this book:
  - check out this repo to `~/src`
  - install all the packages we will rely on in the book
  - prepare all the examples

In order to launch packer, run `make build`. Note, that you will only need to dowload the iso image once, and that it will be placed in `./packer_cache`.

## Credits

Thanks to https://github.com/ruzickap/packer-templates for figuring out the preseed config for ubuntu desktops!