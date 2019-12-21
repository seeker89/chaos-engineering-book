CFLAGS=-O0

all: mystery000 mystery001 faas

%.o: %.c
	cc -o $@ $< $(CFLAGS)

faas:
	sudo ln -f -s /home/chaos/src/examples/killer-whiles/faas001_a.service /lib/systemd/system/faas001_a
	sudo ln -f -s /home/chaos/src/examples/killer-whiles/faas001_b.service /lib/systemd/system/faas001_b
	sudo systemctl daemon-reload

.PHONY: fass