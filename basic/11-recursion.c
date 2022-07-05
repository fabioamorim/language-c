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

int factorial(int n){

    if(n==0) return 1;
    else if(n>0) return factorial(n-1)*n;
    
}

int pow1(int n, int m){
    
    if(m==0)
        return 1;
    return pow1(n,(m-1))*n;
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

    printf("factorial: %d\n", factorial(5));
    
    printf("Pow: %d\n", pow1(5, 3));

    return 0;
}