all: dublist

dublist: dublist.o 
	gcc -o dublist dublist.o

dublist.o: dublist.c dublist.h
	gcc -Wall -c dublist.c

clean:
	rm *o dublist
