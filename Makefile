mp3: dublist

dublist: dublist.o 
	gcc -o mp3 dublist.o

dublist.o: dublist.c dublist.h
	gcc -Wall -c dublist.c

clean:
	rm *o mp3
