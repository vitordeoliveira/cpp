CC=gcc
CFLAGS=-g -Wall
SRC=src
OBJ=obj
SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
# OBJS=obj/allocator.o obj/memtest.o
BINDIR = bin
BIN = bin/main
SUBMITNAME=project5.zip

all:$(BIN)

release: CFLAGS=-Wall -O2 -DNDEBUG
release: clean
release: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(BINDIR)/* $(OBJ)/*

submin:
	$(RM) $(SUBMITNAME)
	zip $(SUBMITNAME) $(BIN)

debug:
	$(info $$SRCS = $(SRCS))
	$(info $$OBJS = $(OBJS))