BIN= bin
CFLAGS= -g -Wall -std=c++0x
CC= g++

all: $(patsubst %.cpp,$(BIN)/%,$(wildcard *.cpp))

$(BIN)/%: %.cpp
	mkdir -p bin
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(BIN)/*
