#ifdef DUBLIST
#define DUBLIST

typedef struct mp3 {
	char *artist;
	char *title;
	char *date;
	int runtime;
	struct mp3 *prev;
	struct mp3 *next;
} mp3;

typedef struct dlist {
	mp3 *head;
	mp3 *tail;
}

void add(char *artist, char *title, char *date, int runtime, dlist *dl);

int del(char *artist, dlist *dl);

void printForward(dlist *dl);

void printRearward(dlist *dl);


#endif
