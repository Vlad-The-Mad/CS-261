#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#define TYPE int

struct linkedlist {
  int size;
  struct link* first;
  struct link* last;
};

struct link {
  TYPE value;
  struct link* next;
  struct link* previous;
};

void init(struct linkedlist* thing) {
  assert (thing != NULL);
  /*Create header sentenel*/
  struct link* sentenel = (struct link *)malloc(sizeof(struct link));
  assert(sentenel != 0);
  thing->first = sentenel;
  thing->first->value = 0;
  thing->first->previous = NULL;

  /*Create end sentenel*/
  struct link* sentenelb = (struct link *)malloc(sizeof(struct link));
  assert(sentenelb != 0);
  thing->last = sentenelb;
  thing->last->value = 0;
  thing->last->next = NULL;

  thing->first->next = thing->last;
  thing->last->previous = thing->first;

  thing->size = 0;
}

int queisempty(struct linkedlist* a) {
  if (a->size == 0)
    return 1;
  else return 0;
}

void addtofront(struct linkedlist* lst, TYPE addval) {
  assert (lst != NULL);
  struct link* newlink = (struct link *)malloc(sizeof(struct link));
  newlink->value = addval;
  newlink->previous = lst->first;
  newlink->next = lst->first->next;
  lst->size += 1;
}

int main () {
  struct linkedlist* testlinkedlist =  (struct linkedlist*)malloc(sizeof(struct linkedlist));
  init(testlinkedlist);
  int empty = queisempty(testlinkedlist);
  printf("is empty? %d \n", empty);
  addtofront(testlinkedlist, 24);
  empty = queisempty(testlinkedlist);
  printf("is empty? %d \n", empty);
}
