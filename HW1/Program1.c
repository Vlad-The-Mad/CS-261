/* CS261- HW1 - Program1.c*/
/* Name: Vladimir Vesely
 * Date: April 3, 2018
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int foo(int* a, int* b, int c){
    /* Increment a */
    (*a)++;
    /* Decrement  b */
    (*b)--;
    /* Assign a-b to c */
    c = *a - *b;
    /* Return c */
    return c;
}

int main(){
    srand(time(NULL));
    /* Declare three integers x,y and z and initialize them randomly to values in [0,10] */
    int x = rand () % 11;
    int y = rand () % 11;
    int z = rand () % 11;
    /* Print the values of x, y and z */
    printf("x: %d \n", x);
    printf("y: %d \n", y);
    printf("z: %d \n", z);

    /* Call foo() appropriately, passing x,y,z as parameters */
    int foo_ret_value = foo(&x, &y, z);

    /* Print the values of x, y and z */
    printf("x after foo: %d \n", x);
    printf("y after foo: %d \n", y);
    printf("z after foo: %d \n", z);

    /* Print the value returned by foo */
    printf("foo: %d \n", foo_ret_value);

    /* Is the return value different than the value of z?  Why? */
    /*Yes.  Foo does not take in the address of z, so modifying c
    does not change the value of z.*/
    return 0;
}
