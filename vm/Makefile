packer_bin ?= packer
template_file ?= ./packer.json
output_dir=./ubuntu-18.04-desktop-amd64-virtualbox-output
revision ?= $(shell git rev-parse HEAD)
vm_name ?= chaos-engineering-in-action-vm-${revision}

validate:
	${packer_bin} validate ${template_file}

build: validate
	${packer_bin} build -on-error=ask ${template_file}
	ls -al ${output_dir}

package:
	zip -s 2g ${vm_name}.zip ${output_dir}/*
	shasum -a 256 ${vm_name}* | tee ${vm_name}.checksums

.PHONY: validate build package