/* CS261- HW1 - Program2.c*/
/* Name: Vladimir Vesely
 * Date: April 3, 2018
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct student{
	char initials[2];
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student *stud = (struct student*)calloc(10, sizeof(struct student));
     /*return the pointer*/
     if (stud == NULL)
      printf("Failed to allocate pointer \n");
     return stud;
}

void generate(struct student* students){
     /*Generate random initials and scores for ten students.
	The two initial letters must be capital and must be between A and Z.
	The scores must be between 0 and 100*/
  if (students == NULL)
    printf("variable students is null \n");
  int i;
  for (i = 0; i < 10; i++) {
    students[i].score = rand () % 101;
    students[i].initials[0] = 'A' + (rand () % 26);
    students[i].initials[1] = 'A' + (rand () % 26);
  }
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              1. Initials  Score
              2. Initials  Score
              ...
              10. Initials Score*/
              int i;
              for (i = 0; i < 10; i++) {
                char initial1 = students[i].initials[0];
                char initial2 = students[i].initials[1];
                int score = students[i].score;
                printf("%c%c %d \n", initial1, initial2, score);
              }
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
    int i;
    int a = 101;
    for (i = 0; i < 10; i++) {
        if (students[i].score < a)
          a = students[i].score;
    }
    printf("Min score: %d\n", a);
    a = 0;
    for (i = 0; i < 10; i++) {
        if (students[i].score > a)
          a = students[i].score;
    }
    printf("Max score: %d\n", a);
    a = 0;
    for (i = 0; i < 10; i++) {
      a += students[i].score;
    }
    a = a/10;
    printf("Average score: %d\n", a);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
     free(stud);
}

int main(){
    struct student* stud = NULL;

    /*call allocate*/
    stud = allocate();
    /*call generate*/
    generate(stud);
    /*call output*/
    output(stud);
    /*call summary*/
    summary(stud);
    /*call deallocate*/
    deallocate(stud);
    return 0;
}
