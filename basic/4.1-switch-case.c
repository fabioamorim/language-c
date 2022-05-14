#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n;

    scanf("%i", &n);

    switch(n) {

        case 1:
            printf("The option 1 was selected!");
            break;
        case 2:
            printf("The option 2 was selected!");
            break;
        case 3:
            printf("The option 3 was selected!");
            break;
        default:
            printf("None option was selected!");
            break;
    }

    printf("\n\n");
    system("pause");
    return 0;

}   