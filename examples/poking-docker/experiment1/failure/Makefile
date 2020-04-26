tag ?= experiment1-failure

build:
	docker build -t ${tag} .

run:
	docker run --rm -ti ${tag}

.PHONY: build run