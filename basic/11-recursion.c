#include <stdio.h>

void printNumbers(int start, int end){
    printf("%d \n", start);
    if(start<end)
        printNumbers(start+1, end);
}

int main(){

    int start = 10, end = 20;
/*  
    Iterative way
    for(int i=start;i<=end;i++)
        printf("%d \n", i);
*/
    printf("\n\n");

    // recursive way
    printNumbers(start, end);

    return 0;
}