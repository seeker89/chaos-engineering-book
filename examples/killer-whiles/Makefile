CFLAGS=-O0

all: mystery000 mystery001 faas

%.o: %.c
	cc -o $@ $< $(CFLAGS)

faas:
	(cd /lib/systemd/system/ && sudo ln -f -s /home/chaos/src/examples/killer-whiles/faas001_a.service faas001_a)
	(cd /lib/systemd/system/ && sudo ln -f -s /home/chaos/src/examples/killer-whiles/faas001_b.service faas001_b)
	sudo systemctl daemon-reload

.PHONY: fass