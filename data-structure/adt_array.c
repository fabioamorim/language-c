#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

/*
    Abstract Data Type - Array

    Is an Array implementation with functions:

    Array structure:
    
    -Array space;
    -Total size;
    -Current lenght

    Functions:

    void Initialize(struct Array arr) - initialize the array structure.
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
    int BinarySearch(struct Array arr, int value) -  the function return the index if the value was found in arra,
        if not found, reutnr an invalid index -1. As the name inform, it uses a binary search method.
    int RBinzarySearch(struct Array arr, int l, int h, int value) - this function is BinarySearch recursive version.
        is required pass low and high current index of array.
    int GetByIndex(struct Array arr, int index) - return the value of array by index. To return if array is empty or
    the index does not exist in array, return -999999999.
    int GetByVAlue(Struct Array arr, int value) - return the index of array by value. For convinience, it's used 
        LinearSearch to get the index.
    int Max(struct Array arr) - return the max value in array.
    int Min(struct Array arr) - return the min vlaue in array.
    int Sum(struct Array arr) - return the sum of array values.
    int RSum(struct Array arr, int sum, int i) - this function is Sum recursive version.
    void Reverse(struct Array *array) - invert the value of array.
    struct Array Merge(struct Array a, struct Array b) - Merge tha a and b array and return a new array.

*/

struct Array{
    int *A;
    int size;
    int length;
};

void Initialize(struct Array *arr, int size){
    if(size > 0){
        arr->A=(int *)malloc(size*sizeof(int));
        arr->size=size;
        arr->length=0;
    }
}

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

int BinarySearch(struct Array arr, int value){

    /*
        Attention!
        Binary search just work if array is sorted.
        In this case, we will check if is sorted, depend the result, apply sort function. 
    */

    if(IsSorted(arr)==false)
        SimpleSort(&arr);

    int h=arr.length;
    int l=0;
    int middle;

    while(l<=h){
        middle=(h+l)/2;
        if(arr.A[middle]==value)return middle;
        else if(arr.A[middle]>value) h=middle-1;
        else l=middle+1;
    }

    return -1;
}

int RBinarySearch(struct Array arr, int l, int h, int value){

    if(l>h) return -1;

    /*
        Attention!
        Binary search just work if array is sorted.
        In this case, we will check if is sorted, depend the result, apply sort function. 
    */

    if(IsSorted(arr)==false)
        SimpleSort(&arr);

    int middle = (h+l)/2;

    if(arr.A[middle] == value) return middle;
    else if(arr.A[middle]>value) return RBinarySearch(arr, l, middle-1, value);
    else return RBinarySearch(arr, middle+1, h, value);

}

int GetByIndex(struct Array arr, int index){

    if(IsEmpty(arr)) return -999999999; // return big negative integer if the array is empty.
    if(index >= 0 && arr.length > index)
        return arr.A[index];

    return -999999999; // return big negative integer if the index does not have value.
}

int GetByValue(struct Array arr, int value){
    return LinearSearch(arr, value);
}

int Max(struct Array arr){

    if(arr.length == 0) return 0;

    int max = arr.A[0];

    for(int i=0;i<arr.length;i++)
        if(arr.A[i] > max) max = arr.A[i];

    return max;
}

int Min(struct Array arr){

    if(arr.length == 0) return -999999999;

    int min = arr.A[0];

    for(int i=0;i < arr.length;i++)
        if(arr.A[i] < min) min = arr.A[i];

    return min;
}

int Sum(struct Array arr){

    int sum=0;

    for(int i=0;i < arr.length; i++)
        sum+= arr.A[i];

    return sum;
}

int RSum(struct Array arr, int sum, int i){
    
    if(i<0) return sum;
    sum+=arr.A[i];
    return RSum(arr, sum, i-1);
}

void Reverse(struct Array *arr){

    if(IsEmpty(*arr)==false){
       for(int i=0, j=arr->length-1;i<j;i++,j--)
           Swap(&arr->A[i], &arr->A[j]);
       
    }
}

struct Array Merge(struct Array a, struct Array b){
    
    /*
        It will be merge array a and array b in a new array.
        The required is the sum of a and b array should be the Array A[size].
    */

    struct Array aux;
    Initialize(&aux, (a.size+b.size));

    for(int i=0;i<a.length;i++)
        Insert(&aux,aux.length,a.A[i]);

    for(int i=0;i<b.length;i++)
        Insert(&aux,aux.length,b.A[i]);
    
    return aux;
}

int main(){

    struct Array a;
    struct Array b;

    Initialize(&a,5);
    Initialize(&b,5);

    Insert(&a,a.length,33);
    Insert(&a,a.length,5);
    Insert(&a,a.length,71);
    Insert(&a,a.length,1);
    Insert(&a,a.length,9);

    Insert(&b,b.length,200);
    Insert(&b,b.length,82);
    Insert(&b,b.length,4);
    Insert(&b,b.length,2);
    Insert(&b,b.length,8);

    Display(a);
    Display(b);

    int size = a.size + b.size;

    struct Array c;
    Initialize(&c, size);

    c=Merge(a,b);

    Display(c);
    
    return 0;
}