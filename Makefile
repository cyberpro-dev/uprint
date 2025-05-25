CC=clang
CFLAGS=-nostdlib -static -Iinclude -O2

all: test

start.o: src/start.S
	$(CC) $(CFLAGS) -c src/start.S -o start.o

uprint.o: src/uprint.c
	$(CC) $(CFLAGS) -c src/uprint.c -o uprint.o

test.o: test.c
	$(CC) $(CFLAGS) -c test.c -o test.o

test: start.o uprint.o test.o
	ld -static -o test start.o uprint.o test.o

clean:
	rm -f *.o test
