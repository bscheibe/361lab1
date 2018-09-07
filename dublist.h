#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef MP3_T
#define MP3_T

struct mp3;
struct dlist;
// Struct containing information about songs. 
typedef struct mp3 {
	char *artist;
	char *title;
	char *date;
	int runtime;
	struct mp3 *prev;
	struct mp3 *next;
} mp3;

// Doubly linked list pointer for the mp3 struct.
typedef struct dlist_t {
	mp3 *head;
	mp3 *tail;
} dlist;

#endif

// add an mp3 to the end of the list.
void add(char *artist, char *title, char *date, int runtime, dlist *dl);

// delete all mp3s with a given artist.
int del(char *artist, dlist *dl);

// print the list, front to back.
void printForward(dlist *dl);

// print the list, back to front. 
void printRearward(dlist *dl);

