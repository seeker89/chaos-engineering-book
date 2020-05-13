CC=cc
CFLAGS=-O0
HEADERS=$(shell find ./legacy -name "*.h")
OBJ=$(shell find ./legacy -name "*.h" | sed 's/\.h/\.o/g')
TARGET=main

all: main

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(HEADERS) $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) main.c

clean:
	rm $(OBJ) $(TARGET)

.PHONY: clean
