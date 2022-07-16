#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

/*

    Abstract Data Type - Array

    Is an Array implementation with functions:

    Array structure:
    -Array space;
    -Total sice;
    -Current lenght

    Functions:

    bool IsEmpty(struct Array arr); - return true if array is empty and false is exists data. 
    bool IsFull(struct Array arr) - return true if there is not space to add new data and false is exists space.
    void Display(strcut Array arr) - show all elements in array. 
    void Insert(struct Array arr, int index, int value)- Add new value in array, passing the value and the index.


*/

struct Array{
    int A[10];
    int size;
    int length;
};

bool IsEmpty(struct Array arr){
    if(arr.length>0) return false;
    return true;
}

bool IsFull(struct Array arr){
    if(arr.length==arr.size) return true;
    return false;
}

void Display(struct Array arr){
    if(IsEmpty(arr)) printf("The array is empty!\n");
    else{
        for(int i=0;i<arr.length;i++)
            printf("%d ", arr.A[i]);
    }
    printf("\n");
}

int Delete(struct Array *arr, int index){

    if(IsEmpty(*arr)) return -1;
    int x=0;

    if(index>=0 && index<arr->length){
        x=arr->A[index];
        for(int i=index;i<arr->length-1;i++){
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
        return x;
    }

    return -1;
}

void Insert(struct Array *arr, int index, int value){
    
    if(index>=0 && index <= arr->length){

        for(int i=arr->length;i>index;i++)
            arr->A[i]=arr->A[i-1];
        arr->A[index]=value;
        arr->length++;
    }
}

int main(){

    struct Array arr ={{},10,0};

    Insert(&arr,0,10);
    printf("Number was removed: %d\n", Delete(&arr,0));
    Display(arr);
    Insert(&arr,0,20);
    Display(arr);
    Insert(&arr,1,30);
    Insert(&arr,2,40);
    Insert(&arr,3,50);
    Insert(&arr,4,60);
    printf("Number was removed: %d\n", Delete(&arr,1));
    Display(arr);


    return 0;
}