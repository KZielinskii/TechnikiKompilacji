CC = g++
CFLAGS = -Wall -Werror -Wno-error=unused-function

SRCS = emitter.cpp main.cpp symbol.cpp tokens.cpp lexer.cpp parser.cpp
OBJS = $(SRCS:.cpp=.o)


TARGET = Kompilator_podstawowy

all: lexer.cpp parser.cpp $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) -lfl

lexer.cpp: lexer.lex
	flex -l -o lexer.cpp lexer.lex

parser.cpp parser.hpp: parser.y
	bison -v -t -d -o parser.cpp parser.y

%.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f *.o $(TARGET) lexer.cpp parser.cpp parser.hpp parser.output

.PHONY: all clean
