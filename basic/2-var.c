#include <stdio.h>
#include <stdlib.h>

// global variable
int x = 5;

void display(){
    printf("Global variable: %i\n", x);
}

int main()
{
    // local variable
    int y = 10;

    printf("Local variable: %i\n", y);

    display();

    printf("Global variable: %i\n", x);

    printf("\n\n");
    system("pause");
    return 0;
    
}