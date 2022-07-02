#include <stdio.h>

void printNumbers(int start, int end){
    printf("%d \n", start);
    if(start<end)
        printNumbers(start+1, end);
}

void func(int n){
    if(n>0){
        printf("Ascending: %d\n", n);
        func(n-1);
        printf("Descending: %d\n", n);
    }
}

void recursionTree(int n){
    if(n>0){
        printf("%d\n", n);
        recursionTree(n-1);
        recursionTree(n-1);
    }
}

int main(){

    int start = 3, end = 20;
/*  
    Iterative way
    for(int i=start;i<=end;i++)
        printf("%d \n", i);
*/
    printf("\n\n");

    // recursive way
    // printNumbers(start, end);

    recursionTree(start);

    return 0;
}