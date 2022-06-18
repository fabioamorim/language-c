#include <stdio.h>
#include <stdlib.h>

int main()
{

    /*
        Advantages of Arrays
            - Simple and easy to use;
            - Faster access to the elements (constant access).
        Disavantages of Arrays
            - Prellocates all needed memory up front and wates memory space for indices in 
                the array that are empty.
            - Fized size: THe size of the array is static (specify the array size before using it).
            - Complex position-based insertion: To insert an element at a given position, we may
                need to shift the existing elements. This will create a position for us to insert
                the new element at the deisred position. If the position at which we want to add
                an element is at the beginning, then the shifting operation is more expensive.
    */

    int vetor[5] = {1,2,3,4,5};
    int matriz[3][3];
    int i, j;

    for (i=0;i<5;i++) {
        printf("Matriz: %i\n", vetor[i]);
    }

    // Insert values in matriz
    for (i=0;i<3;i++) {
        for(j=0; j<3;j++) {
            matriz[i][j] = i;
        }
    }

    // Check the matriz values
    for (i=0;i<3;i++) {
        for(j=0; j<3;j++) {
            printf("Matriz number: %i\n", matriz[i][j]);
        }
    }

    printf("\n\n");
    system("pause");
    return 0;

}