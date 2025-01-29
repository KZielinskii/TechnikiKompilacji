CC = gcc
CFLAGS = -Wall -g -Wno-unused-function

PROJECT_NAME = Start

objects = emitter.o error.o main.o parser.o symbol.o lexer.o

all: $(PROJECT_NAME)

$(PROJECT_NAME): $(objects)
	$(CC) -o $(PROJECT_NAME) $(objects)

emitter.o: emitter.c global.h
	$(CC) $(CFLAGS) -c emitter.c

error.o: error.c global.h
	$(CC) $(CFLAGS) -c error.c

main.o: main.c global.h
	$(CC) $(CFLAGS) -c main.c

parser.o: parser.c global.h
	$(CC) $(CFLAGS) -c parser.c

symbol.o: symbol.c global.h
	$(CC) $(CFLAGS) -c symbol.c

lexer.c: lexer.lex 
	flex -o lexer.c lexer.lex

lexer.o: lexer.c global.h
	$(CC) $(CFLAGS) -c lexer.c


.PHONY: clean

clean:
	rm -f $(PROJECT_NAME) $(objects) lexer.c
