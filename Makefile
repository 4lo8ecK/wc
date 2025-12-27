CC=gcc
FLAGS=-Wall
SRC=wc.c
HDR=

all: wc

wc: $(SRC)
	$(CC) $(FLAGS) $(SRC) -o wc

