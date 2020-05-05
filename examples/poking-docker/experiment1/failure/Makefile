tag ?= experiment1-failure

build:
	docker build -t ${tag} .

run:
	docker run --rm -ti ${tag}

run2:
	docker run --storage-opt size=1g --rm -ti ${tag}

.PHONY: build run run2
