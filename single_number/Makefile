BIN= bin
CFLAGS= -g -Wall
CC= g++

all: $(BIN)/single $(BIN)/single_nomem

$(BIN)/single: single.cpp
	$(CC) $(CFLAGS) -o $@ $^
$(BIN)/single_nomem: single_nomem.cpp
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(BIN)/*
