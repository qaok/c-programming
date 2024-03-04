CC = gcc
CFLAGS = -std=gnu99 -pedantic -Wall
test: test.o
	gcc -o test test.o
.PHONY: clean depend
clean:
	rm -f test *.o *.c~ *.h~
depend:
	makedepend test.c
