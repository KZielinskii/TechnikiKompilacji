CC = gcc
CFLAGS = -Wall -g -Wno-unused-function

PROJECT_NAME = Start

objects = error.o main.o symbol.o lexer.o parser.o

all: $(PROJECT_NAME)

$(PROJECT_NAME): $(objects)
	$(CC) -o $(PROJECT_NAME) $(objects)

parser.c parser.h: parser.y
	bison -d -o parser.c parser.y

parser.o: parser.c parser.h global.h
	$(CC) $(CFLAGS) -c parser.c

error.o: error.c global.h parser.h
	$(CC) $(CFLAGS) -c error.c

main.o: main.c global.h parser.h
	$(CC) $(CFLAGS) -c main.c

symbol.o: symbol.c global.h parser.h
	$(CC) $(CFLAGS) -c symbol.c

lexer.c: lexer.lex
	flex -o lexer.c lexer.lex

lexer.o: lexer.c global.h parser.h
	$(CC) $(CFLAGS) -c lexer.c

.PHONY: clean

clean:
	rm -f $(PROJECT_NAME) $(objects) lexer.c parser.c parser.h
