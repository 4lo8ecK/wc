CC=gcc
FLAGS=-Wall
MAIN=main.c
WC=wc/wc.c wc/wc.h

all: wc

wc: main.o wc.o
	$(CC) $(FLAGS) main.o wc.o -o wc

main.o: $(MAIN)
	$(CC) $(FLAGS) -c $(MAIN)

wc.o: $(WC)
	$(CC) $(FLAGS) -c $(WC)

test: $(MAIN)
	$(CC) $(FLAGS) -D TEST $(MAIN) -o test

clean:
	rm *.o
	rm *.gch