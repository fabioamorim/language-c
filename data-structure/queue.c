#include <stdio.h>
#include <stdbool.h>

#define MAX 10

typedef int TYPE;

typedef struct
{
    TYPE num;
}REGISTER;

typedef struct
{
    REGISTER CONTENT[10];
    int numReg;
}QUEUE;

void initialize(QUEUE* Q){
    Q->numReg = 0;
}

int size(QUEUE* Q){
    return Q->numReg;
}

// isFull: check if the  list is full.
bool isFull(QUEUE* Q){
    if(size(Q) < MAX )
        return false;
    
    return true;

}

// isEmpty: check if the list is empty.
bool isEmpty(QUEUE* Q){
    if(size(Q) == 0)
        return true;
    
    return false;
}

// add: add new element in the queue.
bool add(QUEUE* Q, TYPE element){

    if(isFull(Q))
        return false;
    printf("Adding the element %i in Queue.\n", element);

    Q->CONTENT[Q->numReg].num = element;
    Q->numReg ++;

    return true;
}

// remove: remove the first element in the queue.
bool remove(QUEUE* Q){

    if(isEmpty(Q)){
        printf("The Queue is already empty!\n");
        return false;
    }
       
    int i = 0;
    int element = Q->CONTENT[0].num;

    for(i;i<Q->numReg;i++){
        if(Q->numReg > 0 && Q->numReg < MAX ){
            Q->CONTENT[i].num = Q->CONTENT[i+1].num;  
        }
    }

    printf("The first element %i in the Queue was removed\n", element);
    Q->numReg --;
    return true;

}

// showQueue: show all queue's elements.
void showQueue(QUEUE* Q){

    printf("\nQueue:\n");
    if(isEmpty(Q)){
        printf("The Queue is empty!\n");
    }else{
        int i = 0;
        for(i;i<Q->numReg;i++){
            printf("Value in queue: %i\n", Q->CONTENT[i].num);
        }
    }

}

int main()
{

    QUEUE Q;

    initialize(&Q);

    remove(&Q);
    add(&Q, 100);
    add(&Q, 0);
    add(&Q, 22);
    add(&Q, 12);
    add(&Q, 1);
    add(&Q, 50);
    showQueue(&Q);
    remove(&Q);
    showQueue(&Q);
    remove(&Q);
    showQueue(&Q);
    remove(&Q);
    showQueue(&Q);

    return 0;
}
