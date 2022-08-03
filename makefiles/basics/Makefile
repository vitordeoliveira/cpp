CC=gcc


all: hello test.o

hello: hello.c
	$(CC) -o hello hello.c

test.o: test.c
	$(CC) -c test.c -o test.o

clean: 
	rm hello *.o
