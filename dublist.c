#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 128

// Struct containing the relevant information that we care about.
typedef struct mp3 {
    char *artist;
    char *title;
    char *date;
    int *runtime;
    struct node *prev;
    struct node *next;
} mp3_t;

// Allocates a new node with the given parameters. It becomes the head if
// there is none, and is added to the end of the list otherwise.
void add(char[] artist, char[] title, char[] date, int runtime,
      struct mp3 *head, struct mp3 *tail) {
    struct node *temp;
    temp = (struct mp3*)malloc(sizeof(struct mp3));
    temp->artist = artist;
    temp->title = title;
    temp->date = date;
    temp->runtime = runtime;
    if (head == NULL) {
      head = temp;
      tail = temp;
      head->next=NULL;
      head->prev=NULL;
    } else {
      tail->next = temp;
      temp->prev = tail;
      tail = temp;
    }
}

// Deletes all nodes with the given artist's name
int delete(char[] artist, struct mp3 *head, struct mp3 *tail) {
    int deletions = 0;
    struct node *temp, *prev, *next;
    temp = head;
    while (temp != NULL) {
      if (strcmp(temp->artist, artist)) {
        if (temp == head) {
          head = temp->next;
          free(temp);
          head->prev = NULL;
          deletions++;
        } else if (temp == tail) {
            tail = temp->prev;
            free(temp);
            tail->next = NULL;
          }
        } else {
          prev->next = temp->next;
          temp->prev = prev;
          free(temp);
          deletions++;
        }
      } else {
        prev = temp;
        temp = temp->next;
      }
    }
    return deletions;
}

// Prints out the list in forward order.
void printForward(struct mp3 *r) {
    r = head;
    if (r == NULL) {
      return;
    }
    while (r != NULL) {
      printf("%s by %s from %s, %d seconds long.\n",
        r->title,r->artist,r->date,r->runtime);
      r=r->next;
    }
    printf("\n");
}

// Prints out the list in reverse order.
void printRearward(struct mp3 *r) {
    r = tail;
    if (r == NULL) {
      return;
    }
    while (r != NULL) {
      printf("%s by %s from %s, %d seconds long.\n",
        r->title,r->artist,r->date,r->runtime);
      r=r->prev;
    }
    printf("\n");
}

// Our main function. Uses an int for a switch-case loop. Initializes
// three arrays three of for our user inputs, an int for our fourth,
// and three struct pointers for the start & end of our list, as well
// as our current node.
int  main() {
    int i, runtime;
    char[BUFFERSIZE] artist;
    char[BUFFERSIZE] title;
    char[BUFFERSIZE] date;
    struct mp3 *mp3, *head, *tail;
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
                 scanf("%d",&title);
                 printf("Enter the artist's name : ");
                 scanf("%s",&artist);
                 printf("Enter the date of song : ");
                 scanf("%s",&date);
                 printf("Enter the runtime of the song : ");
                 scanf("%s",&title);
                 add(artist, title, date, runtime, head, tail);
                 break;
        case 2:
                if (head == NULL) {
                  printf("List is Empty\n");
                } else {
                  printf("Song(s) in the list are : ");
                }
                printForward(head);
                break;
        case 3:
                if (head == NULL)
                  printf("List is Empty\n");
                else {
                  printf("Enter the Artist whose tracks
                    you wish to delete : ");
                  scanf("%s",&artist);
                printf("deleted %d tracks successfully\n",
                  delete(artist, head, tail);
                break;
        case 4:
                return 0;
        default:
                printf("Invalid option\n");
        }
      }
    }
    return 0;
}
