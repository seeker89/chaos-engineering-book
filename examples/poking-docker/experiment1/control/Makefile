tag ?= experiment1-control

build:
	docker build -t ${tag} .

run:
	docker run --rm --name experiment1-control -ti ${tag}

.PHONY: build run
