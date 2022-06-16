#include <stdio.h>
#include <stdlib.h>

// This function receives the pointer and increments the variable number one more.
void increment(int *n){
    *n = *n+1;
}

int main()
{

    int x, *px;

    x = 20;

    px = &x;// Passing the memory address to pointer.

    printf("Value of x variable: %i\n", x); // Show us the value of x.
    printf("Value of x variable in pointer: %i\n", *px); // Show us the value that is in memory address px.
    printf("Value of memory of x variable: %d\n", &x); // Show us the memory address.
    printf("Value of pointer: %d\n", px); // Show us the memory address.

    *px = 100; // Save the new value in memory address.

    printf("The new x value: %d\n", x);

    /* Result:
    Value of x variable: 20
    Value of x variable in pointer: 20
    Value of memory of x variable: 61ff18
    Value of pointer: 61ff18
    The new x value: 100
    */

    //-------------------------------------------------
    // Pointer of pointer

    int **q;

    q = &px;

    printf("px memory address: %d\n", &px);
    printf("Value of q: %d\n", q); // The value in q is px memory address.
    printf("Value in *q: %d\n", *q);
    printf("Value in **q: %d\n", **q);

    /* Result:
    Address of vairable a in increment = 61ff00
    Address of vairable a in main  = 61ff1c
    a = 11
    */

    //--------------------------------------------------
    // Pointer as function arguments - call by reference

    int n;
    n = 10;

    increment(&n);

    printf("The vale in n: %d", n);

    //--------------------------------------------------
    // Pointer and arrays

    int A[5] = {1,2,3,4,5};

    for(int i=0;i<5;i++)
        printf("The memory addres in A[%d] = %d\n", i, &A[i]);

    /* Result
    The memory addres in A[1] = 6422268
    The memory addres in A[2] = 6422272
    The memory addres in A[3] = 6422276
    The memory addres in A[4] = 6422280

    Notice that we have a memory address every 4 bytes. It's happeing because integer type 
    has 4 bytes in memory.
    */

    printf("\n\n");
    //system("pause");
    return 0;

}