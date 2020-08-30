populate:
	toxiproxy-cli \
		-h $(shell minikube service --url goldpinger-chaos) \
		create chaos \
			-l 0.0.0.0:8080 \
			-u localhost:9090
	toxiproxy-cli \
		-h $(shell minikube service --url goldpinger-chaos) \
		toxic add \
			--type latency \
			--a latency=250 \
			--upstream \
		chaos

delete:
	toxiproxy-cli \
		-h $(shell minikube service --url goldpinger-chaos) \
		delete chaos

.PHONY: populate delete
