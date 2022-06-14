#include <stdio.h>
#include <stdlib.h>

int main()
{

    int x, *px;

    x = 20;

    px = &x;// passing the memory address to pointer.

    printf("Value of x variable: %i\n", x); // show us the value of x.
    printf("Value of x variable in pointer: %i\n", *px); // show us the value that is in memory address px.
    printf("Value of memory of x variable: %x\n", &x); // shou us the memory address.
    printf("Value of pointer: %x\n", px); // show us the memory address.

    *px = 100; // save the new value in memory address.

    printf("The new x value: %d", x);

    /* Result:
    Value of x variable: 20
    Value of x variable in pointer: 20
    Value of memory of x variable: 61ff18
    Value of pointer: 61ff18
    The new x value: 100
    */

    printf("\n\n");
    system("pause");
    return 0;

}