CC=g++
FLAGS=-Wall
MAIN = main.cpp
WC = wc/wc.cpp wc/wc.hpp
APPNAME = wc

all: app

app: main.o wc.o
	$(CC) $(FLAGS) main.o wc.o -o $(APPNAME)

main.o: $(MAIN)
	$(CC) $(FLAGS) -c $(MAIN)

wc.o: $(WC)
	$(CC) $(FLAGS) -c $(WC)

test1: $(MAIN) wc.o
	$(CC) $(FLAGS) -c -D TEST_ONE $(MAIN)
	$(CC) $(FLAGS) main.o wc.o -o test1

test2: $(MAIN)
	$(CC) $(FLAGS) -D TEST_TWO $(MAIN) -o test2

test3: $(MAIN) wc.o
	$(CC) $(FLAGS) -c -D TEST3 $(MAIN)
	$(CC) $(FLAGS) main.o wc.o -o test3