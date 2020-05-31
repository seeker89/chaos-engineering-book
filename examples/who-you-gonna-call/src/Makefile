CC=cc
CFLAGS=-O0
SRC=$(shell find . -name "*.c")
HEADERS=$(shell find . -name "*.h")
OBJ=$(shell find . -name "*.h" | sed 's/\.h/\.o/g')
TARGET=legacy_server
MAIN=main.c

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(HEADERS) $(OBJ) $(MAIN) $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(MAIN)
	cp $(TARGET) ~

clean:
	rm $(OBJ) $(TARGET)

run: gen $(TARGET)
	./$(TARGET)

gen:
	./generate_legacy.py

tag ?= legacy

docker-build:
	docker build -t ${tag} .

docker-run:
	docker run --rm --name legacy -ti --security-opt seccomp=../profile.json -p 8080:8080 ${tag}

profile:
	curl https://raw.githubusercontent.com/moby/moby/master/profiles/seccomp/default.json | grep -v getpid > profile.json

.PHONY: clean run gen docker-build docker-run
