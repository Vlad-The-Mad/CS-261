#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "skipList.h"
#include <time.h>

/* ************************************************************************
Main Function for Testing
 ************************************************************************ */
/*
 param: no parameters
 pre:	no parameters
 post: prints out the contents of the skip list
*/
int main(){
	int i,M;
	struct skipList *slst1, *slst2;


	 srand ( time(NULL) );

        /* allocate memory to the pointers of Skip List */
	slst1=(struct skipList *)malloc(sizeof(struct skipList));
        slst2=(struct skipList *)malloc(sizeof(struct skipList));
	assert(slst1); assert(slst2);


	/*  Initialize the two skip lists */
	initSkipList(slst1);
        initSkipList(slst2);

	/*  Add to the skip list  M = 20 random integers in [0,100] */
	M=20;
	for(i=0;i<M;i++) addSkipList(slst1, rand()%101);
        for(i=0;i<M;i++) addSkipList(slst2, rand()%101);

	/*  Print out the skip list
            in the breadth-first order, starting from top.
	    In printing, move to a new printing line every time
            the end of the current level is reached.
	    E.g., the print out of a skip list
            with 5 elements should look like

	    7
	    7 14 29
	    3 7 9 14 20

	 */
	printf("\nprint size of list...%d \n", slst1->size);
	printf("\nnext value%d \n", slst1->topSentinel->next->value);
	/*for (i = 0; i < 100; i++)*/
	containsSkipList(slst1, 3);
	printf("\nPrinting of Skip List 1 started ... \n");
	printSkipList(slst1);
	printf("Printing of Skip List 1 finished. \n\n\n");

	printf("\nPrinting of Skip List 2 started ... \n");
	printSkipList(slst2);
	printf("Printing of Skip List 2 finished. \n\n\n");




	/* DIFFERENCE AND MERGING */
        printf("TESTING DIFFERENCE \n");
	printf("Adding the same numbers to both skip lists \n");

	for(i=200; i<=205; i++) {
           addSkipList(slst1, i);
           addSkipList(slst2, i);
	}

        diffSkipList(slst1, slst2);

        printf("\nPrinting of Skip List 1 after difference started ... \n");
	printSkipList(slst1);
	printf("Printing of Skip List 1 after difference finished. \n\n\n");

        printf("TESTING MERGING \n");
        mergeSkipList(slst1, slst2);

        printf("\nPrinting of Skip List 1 after merging started ... \n");
	printSkipList(slst1);
	printf("Printing of Skip List 1 after merging finished. \n\n\n");



	/* Develop test cases for evaluating your functions:
	         int containsSkipList(struct skipList *slst, TYPE e)
	         int removeSkipList(struct skipList *slst, TYPE e)
	 */
        printf("TESTING CONTAINS \n");
	for(i=200; i<=205; i++)
	printf("\n%d %s in the list!.\n",i,containsSkipList(slst1, i)==1?"IS":"IS NOT");

        printf("TESTING REMOVE \n");
	printf("\nRemoving 200,202 and 205 from Skip List 1 started ... \n");
	for(i=200; i<=205; i++) removeSkipList(slst1, i);

	printf("\nPrinting of Skip List 1 after removing started ...\n");
	printSkipList(slst1);
	printf("\nRemoving 200,202 and 205 from Skip list 1 finished ... \n\n\n");


	for(i=200; i<=205; i++)
	printf("\n%d %s in the list!.\n",i,containsSkipList(slst1, i)==1?"IS":"IS NOT");

   return 0;

}


/* ************************************************************************
Internal Functions
 ************************************************************************ */

/* Coin toss function:
 param: 	no parameters
 pre:	no parameres
 post: output is a random intiger number in {0,1} */
int flipSkipLink(void)
{
	return rand() % 2;
}

/* Move to the right as long as the next element is smaller than the input value:
 param: 	current -- pointer to a place in the list from where we need to slide to the right
 param:	e --  input value
 pre:	current is not NULL
 post: returns one link before the link that contains the input value e */
struct skipLink * slideRightSkipList(struct skipLink *current, TYPE e){
	while ((current->next != 0) && LT(current->next->value, e))
		current = current->next;
	return current;
}


/* Create a new skip link for a value
	param: e	 -- the value to create a link for
	param: nextLnk	 -- the new link's next should point to nextLnk
	param: downLnk -- the new link's down should point to downLnk
	pre:	none
	post:	a link to store the value */
struct skipLink* newSkipLink(TYPE e, struct skipLink * nextLnk, struct skipLink* downLnk) {
	struct skipLink * tmp = (struct skipLink *) malloc(sizeof(struct skipLink));
	assert(tmp != 0);
	tmp->value = e;
	tmp->next = nextLnk;
	tmp->down = downLnk;
	return tmp;
}


/* Add a new skip link recursively
 param: current -- pointer to a place in the list where the new element should be inserted
 param: e	 -- the value to create a link for
 pre:	current is not NULL
 post: a link to store the value */
struct skipLink* skipLinkAdd(struct skipLink * current, TYPE e) {

/* FIX ME */
assert (current != NULL);
if (current->down != NULL) {
	struct skipLink* temp = slideRightSkipList(current->down, e);
	current->down = skipLinkAdd (temp, e);
}
struct skipLink* new = newSkipLink(e, current->next, current->down);
current->next = new;
return new;
}


/* ************************************************************************
Public Functions
 ************************************************************************ */

/* Initialize skip list:
 param:  slst -- pointer to the skip list
 pre:	slst is not null
 post: the sentinels are allocated, the pointers are set, and the list size equals zero */
void initSkipList (struct skipList *slst)
{
	slst->size=0;
	slst->topSentinel=(struct skipLink * )malloc(sizeof(struct skipLink));
	assert(slst->topSentinel);
	slst->topSentinel->next=NULL;
	slst->topSentinel->down=NULL;
}

/* Checks if an element is in the skip list:
 param: slst -- pointer to the skip list
 param: e -- element to be checked
 pre:	slst is not null
 post: returns true or false  */
 int containsSkipList(struct skipList *slst, TYPE e)
 {

	 /* FIX ME */
	 assert(slst != NULL);
	 struct skipLink* current = slst->topSentinel->next;
	 do {
		 current = slideRightSkipList(current, e);
		 if (current->next != NULL && current->next->value == e) {
			 return 1;
		 }
		 else
		 current = current->down;
	 }
	 while (current != NULL && current->next != NULL);
	 return 0;
 }


/* Remove an element from the skip list:
 param: slst -- pointer to the skip list
 param: e -- element to be removed
 pre:	slst is not null
 post: the new element is removed from all internal sorted lists */
 void removeSkipList(struct skipList *slst, TYPE e)
 {

	 /* FIX ME */
	 struct skipLink * check = slst->topSentinel;
	 while(check != NULL) {
		 check = slideRightSkipList(check, e);
		 if (check != NULL && check->next != NULL && check->next->value == e) {
			 struct skipLink * temp = check->next;
			 check->next = temp->next;
			 free(temp);
		 }
		 else if (check != NULL)
		 check = check->down;
	 }
 }


/* Add a new element to the skip list:
	param: slst -- pointer to the skip list
	param: e -- element to be added
	pre:	slst is not null
	post:	the new element is added to the lowest list and randomly to higher-level lists */
	void addSkipList(struct skipList *slst, TYPE e)
	{

		/* FIX ME */
		assert(slst != NULL);
		struct skipLink* current = slst->topSentinel;
		do {
			current = slideRightSkipList(current, e);
		/* add to the higher lists*/
			if (flipSkipLink() == 1 || current->down == NULL) {
				struct skipLink* temp = skipLinkAdd(current, e);
				temp->value = e;
			}
		}
		while (current->down != NULL && current->next != NULL && flipSkipLink() != 1);
		slst->size += 1;
	}

/* Find the number of elements in the skip list:
 param: slst -- pointer to the skip list
 pre:	slst is not null
 post: the number of elements */
int sizeSkipList(struct skipList *slst){

	return slst->size;

}


/* Print the links in the skip list:
	param: slst -- pointer to the skip list
	pre:	slst is not null and slst is not empty
	post: the links in the skip list are printed breadth-first, top-down */
	void printSkipList(struct skipList *slst)
	{

		/* FIX ME*/
		assert (slst != NULL && slst->size != 0);
		struct skipLink* temp = slst->topSentinel->next;
		struct skipLink* current = slst->topSentinel->next;
		while (temp != NULL) {
			current = temp;
			while (current != NULL) {
				printf("%f \n", current->value);
				current = current->next;
			}
			temp = temp->down;
		}
	}


/* Merge two skip lists, by adding elements of skip list 2 to skip list 1
 that are not already contained in skip list 1.
 The function should also remove the entire skip list 2 from the memory.
 param: slst1 -- pointer to the skip list 1
 param: slst2 -- pointer to the skip list 2
 pre: slst1 and slst2 are not null, and skip list 1 and skip list 2 are not empty
 post: slst1 points to the merger,  slst2 is null*/
void mergeSkipList(struct skipList *slst1, struct skipList *slst2)
{
	/* FIX ME */
	assert (slst1 != NULL
		&& slst2 != NULL
		&& slst1->size != 0
		&& slst2->size != 0);

		while (slst2->topSentinel->next != NULL) {
			TYPE search_val = slst2->topSentinel->next->value;
			if (containsSkipList(slst1, search_val) != 1) {
				addSkipList(slst1, search_val);
			}
			removeSkipList(slst2, slst2->topSentinel->next->value);
		}

	} /* end of the function */



/* Find a difference of two skip lists
   by removing elements of skip list 2 from skip list 1.
   param: slst1 -- pointer to the skip list 1
   param: slst2 -- pointer to the skip list 2
   pre: slst1 and slst2 are not null, and skip list 1 and skip list 2 are not empty
   post: slst1 points to the merger skip list*/
void diffSkipList(struct skipList *slst1, struct skipList *slst2)
{
/* FIX ME */
	assert (slst1 != NULL
		&& slst2 != NULL
		&& slst1->size != 0
		&& slst2->size != 0);
		struct skipLink* temp = slst2->topSentinel->next;
		while (temp-> down != NULL)
			temp = temp->down;
		while (temp != NULL) {
			TYPE search_val = temp->value;
			if (containsSkipList(slst2, search_val) == 1) {
				removeSkipList(slst1, search_val);
			}
			temp = temp->next;
		}

} /* end of the function */
