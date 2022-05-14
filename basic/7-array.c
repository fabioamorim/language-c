#include <stdio.h>
#include <stdlib.h>

int main()
{

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