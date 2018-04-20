/* bag2set.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynArray.h"


/* Converts the input bag into a set using dynamic arrays
	param: 	da -- pointer to a bag
	return value: void
        result: after exiting the function da points to a set
*/
void bag2set(struct DynArr *da)
{


     /* FIX ME */

}



/* An example how to test your bag2set() */
int main(int argc, char* argv[]){

	int i;
        struct DynArr da;  /* bag */

        initDynArr(&da, 100);
        da.size = 10;
        da.data[0] = 1.3;
	for (i=1;i<da.size;i++){
	    da.data[i] = 1.2;
	 }
    DynArr* da1 = newDynArr(10);
        initDynArr(da1, 100);
        da1->size = 10;
        da1->data[0] = 1.3;
        for (i=1;i<da1->size;i++){
          da1->data[i] = 2.2;
        }
        /*removeAtDynArr(da1, 3);*/
        for (i=0;i<da1->size;i++){
          printf("%g  \n", da1->data[i]);
        }
          printf("\n");
        printf("%d \n", containsDynArr(da1, 1.3));
        for (i=0;i<da1->size;i++){
          printf("%g  \n", da1->data[i]);
        }

        printf("Bag:\n\n");
	for (i=0;i<da.size;i++){
          printf("%g  \n", da.data[i]);
        }

        printf("\n\n\n");
        printf("Set:\n\n");
        bag2set(&da);
	for (i=0;i<da.size;i++){
          printf("%g ", da.data[i]);
        }
        printf("\n");

	return 0;
}
