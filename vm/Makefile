packer_bin ?= packer
template_file ?= ./packer.json
output_dir=./output-qemu/packer-qemu

validate:
	${packer_bin} validate ${template_file}

build: validate
	${packer_bin} build -on-error=ask ${template_file}
	ls -al ${output_dir}


.PHONY: validate build