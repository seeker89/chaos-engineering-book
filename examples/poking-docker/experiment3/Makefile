tag ?= stressful

build:
	docker build -t ${tag} .

run:
	docker run --rm --name stressful -ti ${tag}

.PHONY: build run
