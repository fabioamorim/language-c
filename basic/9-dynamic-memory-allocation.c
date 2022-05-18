#include <stdio.h>
#include <stdlib.h>

void fills_array(int *array, int size_array)
{
    int i = 0;
    for (i;i<size_array;i++){
        printf("Enter with a number: ");
        scanf("%d", &array[i]);
    }
}

int main()
{

    int *p;
    int size_array, i;

    printf("Enter with array size: ");
    scanf("%d", &size_array);

    p = (int *)malloc(size_array * sizeof(int)); // Creating the dynamic space and storing its address in a pointer.

    if (p==NULL) {
        printf("Error in memory allocation!\n");
        system("PAUSE");
        exit(1);
    }

    fills_array(p, size_array);

    for (i=0;i<size_array;i++) {
        printf("Value: %d\n", p[i]);
    }

    free(p);
    printf("\n\n");
    system("pause");
    return 0;

}