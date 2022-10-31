# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g

isomorphic-strings: isomorphic-strings.o
	$(CC) $(CFLAGS) -o isomorphic-strings isomorphic-strings.o

isomorphic-strings.o: isomorphic-strings.cpp
	$(CC) $(CFLAGS) -c isomorphic-strings.cpp

clean:
	rm -rf isomorphic-strings isomorphic-strings.o
