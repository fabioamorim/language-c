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
    printf("value of pointer: %x\n", px); // show us the memory address.

    printf("\n\n");
    system("pause");
    return 0;

}