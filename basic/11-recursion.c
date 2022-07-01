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

int main(){

    int start = 10, end = 20;
/*  
    Iterative way
    for(int i=start;i<=end;i++)
        printf("%d \n", i);
*/
    printf("\n\n");

    // recursive way
    // printNumbers(start, end);

    func(start);

    return 0;
}