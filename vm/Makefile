packer_bin ?= packer
template_file ?= ./packer.json
output_dir=./chaos-engineering-VM
revision ?= $(shell git rev-parse HEAD)
vm_name ?= chaos-engineering-VM-${revision}

validate:
	${packer_bin} validate ${template_file}

build: validate
	${packer_bin} build -on-error=ask ${template_file}
	ls -alh ${output_dir}

package:
	shasum -a 256 ${output_dir}/* | tee chaos-engineering-VM.sha256
	zip -s 1g -sv ${vm_name}.zip ${output_dir}/*
	shasum -a 256 ${vm_name}* | tee parts.sha256
	ls -alh ${vm_name}*

clean:
	rm -rf ${output_dir}

.PHONY: validate build package clean
