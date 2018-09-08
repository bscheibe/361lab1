#include "dublist.h"
#define BUFFERSIZE 128


// Allocates a new node with the given parameters. It becomes the head if
// there is none, and is added to the end of the list otherwise.
void add(char *artist, char *title, char *date, int runtime, dlist *dl) {
	mp3* temp = (mp3*)malloc(sizeof(mp3));
    if (dl->head == NULL) {
      dl->head = temp;
      dl->tail = temp;
      dl->head->next = NULL;
      dl->tail->prev = NULL;
    } else {
      dl->tail->next = temp;
      temp->prev = dl->tail;
      dl->tail = dl->tail->next;
    }
    temp->artist = (char*)malloc(strlen(artist));
    strcpy(temp->artist,artist);
    temp->title = (char*)malloc(strlen(title));
    strcpy(temp->title,title);
    temp->date = (char*)malloc(strlen(date));
    strcpy(temp->date,date);
    temp->runtime = runtime;
}

// Deletes all nodes with the given artist's name
int del(char *artist, dlist *dl) {
    int deletions = 0;
    mp3 *temp = (mp3*)malloc(sizeof(mp3));
    mp3 *deletion = (mp3*)malloc(sizeof(mp3));
    temp = dl->head;
    while (temp != NULL) {
       if (!strcmp(temp->artist, artist)) {
        if (temp == dl->head) { //deleting the first node
	  if (dl->head->next == NULL) { //in case there is no following node
	   dl->head = NULL;
           dl->tail = NULL;
	   free(temp->artist);
	   free(temp->title);
	   free(temp->date);
	   free(temp);
	   deletions++;
	   break; 
          }
	  deletion = dl->head;
          dl->head = dl->head->next;
	  free(deletion->artist);
	  free(deletion->title);
	  free(deletion->date);
          free(deletion);
          temp = dl->head;
          temp->prev = NULL;
          deletions++;
        } else {
		if (temp == dl->tail) { //deleting the tail node
		   dl->tail = temp->prev;
  		   free(temp->artist);
	  	   free(temp->title);
	  	   free(temp->date);
          	   free(temp);
       		   dl->tail->next = NULL;
		   deletions++;
		   break;
       		 } else { //delete a middle node
         	 temp->prev->next = temp->next;
         	 temp->next->prev = temp->prev;
         	 deletion = temp;
                 temp = temp->next;
                 free(deletion->artist);
	         free(deletion->title);
	  	 free(deletion->date);
         	 free(deletion);
          	 deletions++;
                 continue;
        	 }
	}
      } else { // does not match
      temp = temp->next;
     }
    }
    return deletions;
}

// Prints out the list in forward order.
void printForward(dlist *dl) {
	mp3 *temp = dl->head;
    if (temp == NULL) {
	printf("List is empty.");
      return;
    }
    while (temp != NULL) {
      printf("%s by %s from %s, %d seconds long.\n",
        temp->title,temp->artist,temp->date,temp->runtime);
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
        temp->title,temp->artist,temp->date,temp->runtime);
      temp=temp->prev;
    }
    printf("\n");
}

// Our main function. Uses an int for a switch-case loop. Initializes
// three arrays three of for our user inputs, an int for our fourth,
// and three struct pointers for the start & end of our list, as well
// as our current node.
int  main() {
    int i, runtime, len;
    char buffer[BUFFERSIZE];
    char artist[BUFFERSIZE];
    char artistdel[BUFFERSIZE];
    char title[BUFFERSIZE];
    char date[BUFFERSIZE];
    dlist* dl = (dlist*)malloc(sizeof(mp3));
    mp3 *temp = (mp3*)malloc(sizeof(mp3));
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
        break;
      } else {
        switch(i)
      {
        case 1:
                 printf("Enter the title of the track :");
		 getchar();
                 if(fgets(buffer, BUFFERSIZE, stdin) != NULL) {
		  len = (int)strlen(buffer);
		  buffer[len-1] = '\0';
		  strcpy(title,buffer);
		 }
                 printf("Enter the artist's name : ");
                 if(fgets(buffer, BUFFERSIZE, stdin) != NULL) {
		  len = (int)strlen(buffer);
		  buffer[len-1] = '\0';
		  strcpy(artist,buffer);
		 }
                 printf("Enter the date of song : ");
                 if(fgets(buffer, BUFFERSIZE, stdin) != NULL) {
		  len = (int)strlen(buffer);
		  buffer[len-1] = '\0';
		  strcpy(date,buffer);
		 }
                 printf("Enter the runtime of the song : ");
                 scanf("%d" ,&runtime);
                 add(artist, title, date, runtime, dl);
                 break;
        case 2:
                printForward(dl);
                break;
        case 3:
                if (dl->head == NULL)
                  printf("List is Empty\n");
                else {
		  getchar();
                  printf("Enter the Artist whose tracks you wish to delete : ");
                  if(fgets(buffer, BUFFERSIZE, stdin) != NULL) {
		  len = (int)strlen(buffer);
		  buffer[len-1] = '\0';
		  strcpy(artistdel,buffer);
		 }
                printf("deleted %d track(s) successfully\n", del(artistdel, dl));
		}
                break;
        case 4:
		//free
                return 0;
        default:
                printf("Invalid option\n");
        }
      }
    }
    while (dl->head != NULL) {
	  temp = dl->head;
	  free(dl->head->artist);
	  free(dl->head->title);
	  free(dl->head->date);
          free(temp);
    }
    return 0;
}
