CC=gcc
FLAGS=-Wall
MAIN=main.c
WC=wc/wc.c wc/wc.h

TOOLS=tools/str.c tools/str.h

INCLUDE_TOOLS=-I./tools
INCLUDE_WC=-I./wc

all: app

app: main.o wc.o
	$(CC) $(FLAGS) main.o wc.o -o wc

main.o: $(MAIN)
	$(CC) $(FLAGS) $(INCLUDE_TOOLS) $(INCLUDE_WC) -c $(MAIN)

wc.o: $(WC)
	$(CC) $(FLAGS) $(INCLUDE_TOOLS) -c $(WC)

str.o: $(TOOLS)
	$(CC) $(FLAGS) -c $(TOOLS)


#
# TESTS
#
test: $(MAIN)
	$(CC) $(FLAGS) -D TEST $(MAIN) -o test

tstmain.o: $(MAIN)
	$(CC) $(FLAGS) $(INCLUDE_TOOLS) -D TEST2 -c $(MAIN)

tstmain2.o: $(MAIN)
	$(CC) $(FLAGS) $(INCLUDE_TOOLS) $(INCLUDE_WC) -D TEST3 -c $(MAIN)


test2: tstmain.o str.o 
	$(CC) $(FLAGS) main.o str.o -o test2

test3: tstmain2.o wc.o str.o
	$(CC) $(FLAGS) main.o wc.o str.o -o test3


clean:
	rm ./*.o
	rm ./*.gch