CC=gcc
CFLAGS=-g -Wall

# $@ = Target Name
# $^ = Dependencies

all: myapp

# list.o: list.h list.c
# 	$(CC) $(CFLAGS) -c list.c

# tree.o: tree.h tree.c
# 	$(CC) $(CFLAGS) -c tree.c

%.o: %.h %.c 
	$(CC) $(CFLAGS) -c $^

# %.s: %.c %.h
# 	$(CC) $(CFLAGS) -S $^


# myapp: list.o tree.o main.c
# 	$(CC) $(CFLAGS) -o myapp main.c list.o tree.o
myapp: list.o tree.o main.c #main.o
	$(CC) $(CFLAGS) -o $@ $^

# For otimization use -O2 argument
# time ./myapp to see performance
# gdb ./myapp to debug

clean:
	rm *.o myapp *.gch