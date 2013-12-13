BIN= bin
CFLAGS= -g -Wall
CC= g++

all: $(patsubst %.cpp,$(BIN)/%,$(wildcard *.cpp))

$(BIN)/%: %.cpp
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(BIN)/*
