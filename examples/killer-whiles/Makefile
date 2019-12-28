CFLAGS=-O0

all: mystery000 mystery001 faas

%.o: %.c
	cc -o $@ $< $(CFLAGS)

faas:
	# link our fake faas services
	sudo ln -f -s /home/chaos/src/examples/killer-whiles/faas001_a.service /lib/systemd/system/faas001_a.service
	sudo ln -f -s /home/chaos/src/examples/killer-whiles/faas001_b.service /lib/systemd/system/faas001_b.service
	sudo systemctl daemon-reload
	# link our fake load-balancer
	sudo ln -f -s /home/chaos/src/examples/killer-whiles/nginx.loadbalancer.conf /etc/nginx/conf.d/nginx.loadbalancer.conf
	sudo systemctl restart nginx

.PHONY: fass