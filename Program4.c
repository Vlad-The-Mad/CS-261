/* CS261- HW1 - Program4.c*/
/* Name: Vladimir Vesely
 * Date: April 4, 2018
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct student{
	char initials[2];
	int score;
};

void sort(struct student* students, int n){
  /*Sort n students based on their initials*/
  int sorted = 0;
  int i;
  struct student swap;
  while (sorted == 0) {
    sorted = 1;
    for (i = 0; i < n; i++) {
      if (i < (n - 1) && students[i].initials[0] > students[i + 1].initials[0]) {
        swap = students[i];
        students[i] = students[i + 1];
        students[i + 1] = swap;
        sorted = 0;
      }
      else if (i < (n - 1) && students[i].initials[0] == students[i + 1].initials[0]) {
        if (students[i].initials[1] > students[i + 1].initials[1]) {
          swap = students[i];
          students[i] = students[i + 1];
          students[i + 1] = swap;
          sorted = 0;
        }
      }
    }
  }
}

int main(){
  srand(time(NULL));
  /*Declare an integer n and assign it a value.*/
  int n = 10;
  /*Allocate memory for n students using malloc.*/
  struct student *students = malloc(n * sizeof(struct student));
  /*Generate random IDs and scores for the n students, using rand().*/
  if (n == 0) {
    printf("There aren't any students. \n");
    return 1;
  }
  int i;
  for (i = 0; i < n; i++) {
    students[i].score = rand () % 101;
    students[i].initials[0] = 'A' + (rand () % 26);
    students[i].initials[1] = 'A' + (rand () % 26);
  }

  /*Print the contents of the array of n students.*/
  for (i = 0; i < n; i++) {
    char initial1 = students[i].initials[0];
    char initial2 = students[i].initials[1];
    int score = students[i].score;
    printf("Student no. %d: %c%c %d \n", (i+1), initial1, initial2, score);
  }

  /*Pass this array along with n to the sort() function*/
  sort(students, n);
  /*Print the contents of the array of n students.*/
  for (i = 0; i < n; i++) {
    char initial1 = students[i].initials[0];
    char initial2 = students[i].initials[1];
    int score = students[i].score;
    printf("Student no. %d: %c%c %d \n", (i+1), initial1, initial2, score);
  }

	free(students);
  return 0;
}
