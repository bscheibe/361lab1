#include "dublist.h"
#define BUFFERSIZE 128


// Allocates a new node with the given parameters. It becomes the head if
// there is none, and is added to the end of the list otherwise.
void add(char *artist, char *title, char *date, int runtime, dlist *dl) {
    mp3 *temp;
    temp = (mp3*)malloc(sizeof(mp3));
    temp->artist = artist;
    temp->title = title;
    temp->date = date;
    temp->runtime = &runtime;
    if (dl->head == NULL) {
      dl->head = temp;
      dl->tail = temp;
      temp->next=NULL;
      temp->prev=NULL;
    } else {
      dl->tail->next = temp;
      temp->prev = dl->tail;
      dl->tail = temp;
    }
	printf("%s",head->title);
}

// Deletes all nodes with the given artist's name
int del(char *artist, dlist *dl) {
    int deletions = 0;
    mp3 *temp;
    temp = dl->head;
    while (temp != NULL) {
      if (strcmp(temp->artist, artist)) {
        if (temp == dl->head) {
          dl->head = temp->next;
          free(temp);
          dl->head->prev = NULL;
          deletions++;
        } else {
		if (temp == dl->tail) {
		   dl->tail = temp->prev;
  		   free(temp);
       		   dl->tail->next = NULL;
       		 } else {
         	 temp->prev->next = temp->next;
         	 temp->next->prev = temp->prev;
         	 free(temp);
          	deletions++;
        	}
	}
      } else {
        temp = temp->next;
      }
    }
    return deletions;
}

// Prints out the list in forward order.
void printForward(dlist *dl) {
	mp3 *temp = dl->head;
    if (temp == NULL) {
      return;
    }
    while (temp != NULL) {
      printf("%s by %s from %s, %d seconds long.\n",
        temp->title,temp->artist,temp->date,*(temp->runtime));
      temp=temp->next;
    }
    printf("\n");
}

// Prints out the list in reverse order.
void printRearward(dlist *dl) {
	mp3 *temp = dl->tail; 
   if (temp == NULL) {
      return;
    }
    while (temp != NULL) {
      printf("%s by %s from %s, %d seconds long.\n",
        temp->title,temp->artist,temp->date,*(temp->runtime));
      temp=temp->prev;
    }
    printf("\n");
}

// Our main function. Uses an int for a switch-case loop. Initializes
// three arrays three of for our user inputs, an int for our fourth,
// and three struct pointers for the start & end of our list, as well
// as our current node.
int  main() {
    int i, runtime;
    char artist[BUFFERSIZE];
    char title[BUFFERSIZE];
    char date[BUFFERSIZE];
    dlist dl = (dlist*)malloc(sizeof(dlist));
    head = NULL;
    tail = NULL;
    while (1) {
      printf("\nList Operations\n");
      printf("===============\n");
      printf("1.Insert\n");
      printf("2.Display\n");
      printf("3.Delete\n");
      printf("4.Exit\n");
      printf("Enter your choice : ");
      if (scanf("%d",&i) <= 0) {
        printf("Enter only an Integer\n");
        exit(0);
      } else {
        switch(i)
      {
        case 1:
                 printf("Enter the title of the track : ");
                 scanf("%s",title);
                 printf("Enter the artist's name : ");
                 scanf("%s",artist);
                 printf("Enter the date of song : ");
                 scanf("%s",date);
                 printf("Enter the runtime of the song : ");
                 scanf("%s",title);
                 add(artist, title, date, runtime, dl);
                 break;
        case 2:
                if (dl->head == NULL) {
                  printf("List is Empty\n");
                } else {
                  printf("Song(s) in the list are : ");
                }
                printForward(dl);
                break;
        case 3:
                if (dl->head == NULL)
                  printf("List is Empty\n");
                else {
                  printf("Enter the Artist whose tracks you wish to delete : ");
                  scanf("%s",artist);
                printf("deleted %d tracks successfully\n", delete(artist, dl));
		}
                break;
        case 4:
		temp = dl->head;
		deletingNode = temp->next;
		while (temp != NULL) {
			temp = temp->next;
			free(deletingNode);
		}
		free(dl);
                return 0;
        default:
                printf("Invalid option\n");
        }
      }
    }
    return 0;
}
