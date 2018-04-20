/* CS261- HW1 - Program3.c*/
/* Name: Vladimir Vesely
 * Date: April 4, 2018
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int* number, int n){
  /*Sort the array of integeres of length n*/
  int sorted = 0;
  int i;
  int swap;
  while (sorted == 0) {
    sorted = 1;
    for (i = 0; i < n; i++) {
      if (i < (n - 1) && number[i] > number[i + 1]) {
        swap = number[i];
        number[i] = number[i + 1];
        number[i + 1] = swap;
        sorted = 0;
      }
    }
  }
}

int main(){
    srand(time(NULL));
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    /*Allocate memory for an array of n integers using malloc.*/
    int* array;
    array = malloc(n * sizeof(int));
    /*Fill this array with random numbers, using rand().*/
    int i;
    for (i = 0; i < n; i++) {
      array[i] = rand ();
    }
    /*Print the contents of the array.*/
    for (i = 0; i < n; i++) {
      printf("Element %d: %d\n", (i + 1), array[i]);
    }
    /*Pass this array along with n to the sort() function of part a.*/
    sort(array, n);
    /*Print the contents of the array.*/
    for (i = 0; i < n; i++) {
      printf("Element %d: %d\n", (i + 1), array[i]);
    }
    free(array);
    return 0;
}
