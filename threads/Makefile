CC=g++
CARGS=-pthread
SHELL := /bin/bash

all: build

build: 
	$(CC) $(CARGS) -o index index.cpp

clean:
	rm -v !(*.cpp|"Makefile")