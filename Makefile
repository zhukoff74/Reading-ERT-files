CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = build/rert
SRC = src/main.c

all: $(TARGET)

$(TARGET): $(SRC) | build
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

build:
	mkdir -p build

clean:
	rm -f $(TARGET) $(TARGET).exe

run: $(TARGET)
	./$(TARGET) --file=processing.ert

.PHONY: all clean run build
