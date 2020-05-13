CC=cc
CFLAGS=-O0
HEADERS=$(shell find ./legacy -name "*.h")
OBJ=$(shell find ./legacy -name "*.h" | sed 's/\.h/\.o/g')
TARGET=main

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(HEADERS) $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) main.c

clean:
	rm $(OBJ) $(TARGET)

run: gen $(TARGET)
	./$(TARGET)

gen:
	./generate_legacy.py

.PHONY: clean run gen
