packer_bin ?= packer
template_file ?= ./packer.json
output_dir=./ubuntu-18.04-desktop-amd64-virtualbox-output

validate:
	${packer_bin} validate ${template_file}

build: validate
	${packer_bin} build -on-error=ask ${template_file}
	ls -al ${output_dir}

package:
	zip -s 2g chaos-engineering-in-action-vm-$(shell git rev-parse HEAD).zip ${output_dir}/*
	shasum -a 256 chaos-engineering-in-action-vm-$(shell git rev-parse HEAD)*

.PHONY: validate build package