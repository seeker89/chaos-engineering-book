CFLAGS=-O0

all: mystery000 mystery001 faas

%.o: %.c
	cc -o $@ $< $(CFLAGS)

faas:
	ln faas001_a.service /lib/systemd/system/faas001_a
	ln faas001_b.service /lib/systemd/system/faas001_b
	sudo systemctl daemon-reload

.PHONY: fass