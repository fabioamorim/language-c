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

    bool IsEmpty(struct Array arr) - return true if array is empty and false is exists data. 
    bool IsFull(struct Array arr) - return true if there is not space to add new data and false is exists space.
    void Display(strcut Array arr) - show all elements in array. 
    void Insert(struct Array *arr, int index, int value)- Add new value in array, passing the value and the index.
    void Delete(struct Arra *arr, int index) - Delete a value in array by index, return the value was removed, or
        return -1 if was not possible remove the value.
    void Swap(int *x, int *y) - Change the value of x to y and vice versa.
    bool IsSorted(struct Array arr) - return true if array already sorted and false if is not.
    void SimpleSort(struct Array *arr) - if the array is not sorted, this sort. 
    int LinearSearch(struct Array arr, int value) - the function return the index if the value was found in array,
        if not found, return an invalid index -1.
    int RLinearSearch(struct Array arr, int value, int i) - this function is LinearSearch recursive version.
    

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

void Insert(struct Array *arr, int index, int value){
    
    if(index>=0 && index <= arr->length){

        for(int i=arr->length;i>index;i++)
            arr->A[i]=arr->A[i-1];
        arr->A[index]=value;
        arr->length++;
    }
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

void Swap(int *x, int *y){

    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

bool IsSorted(struct Array arr){
    for(int i=0;i<arr.length-1;i++)
        if(arr.A[i]>arr.A[i+1]) return false;
    
    return true;
}

void SimpleSort(struct Array *arr){

    if(IsEmpty(*arr)==false){

        if(IsSorted(*arr)==false){

            /* 
                If the array already sorted, it does not execute the for loop.
                So it doesn't waste resources.
            */

            for(int i=0;i<arr->length;i++){

                for(int j=0;j<arr->length;j++){
                    if(arr->A[i]<arr->A[j])
                        Swap(&arr->A[i], &arr->A[j]);
                }
            }
        }
    }
}

int LinearSearch(struct Array arr, int value){

    if(IsEmpty(arr)==false)
        for(int i=0;i<arr.length;i++)
            if(value==arr.A[i]) return i;
    
    return -1;
}

int RLinearSearch(struct Array arr, int value, int i){

    if(IsEmpty(arr)==false)
        if(value==arr.A[i]) return i;
        else return RLinearSearch(arr, value, i-1);

    return -1;
}

int main(){

    struct Array arr ={{},10,0};

    Insert(&arr,0,99);
    Insert(&arr,1,88);
    Insert(&arr,2,100);
    Insert(&arr,3,50);
    Insert(&arr,4,22);
    Display(arr);
    SimpleSort(&arr);
    Display(arr);

    printf("%d\n",LinearSearch(arr, 1000));
    printf("%d\n", RLinearSearch(arr,99,arr.length));

    return 0;
}