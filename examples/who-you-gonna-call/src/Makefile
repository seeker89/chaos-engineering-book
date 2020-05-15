CC=cc
CFLAGS=-O0
HEADERS=$(shell find ./legacy -name "*.h")
OBJ=$(shell find ./legacy -name "*.h" | sed 's/\.h/\.o/g')
TARGET=legacy
MAIN=main.c

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(HEADERS) $(OBJ) $(MAIN)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(MAIN)
	cp $(TARGET) ~

clean:
	rm $(OBJ) $(TARGET)

run: gen $(TARGET)
	./$(TARGET)

gen:
	./generate_legacy.py

.PHONY: clean run gen
