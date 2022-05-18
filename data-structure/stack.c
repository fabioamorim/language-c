#include <stdio.h>
#include <stdbool.h>

#define MAX 10 //stack size

typedef int TYPE;

typedef struct{
    TYPE num;
}REGISTER;

typedef struct{
    REGISTER CONTENT[MAX];
    int numReg;
}STACK;

void initialize(STACK* S){
    S->numReg = 0;
}

int size(STACK* S){
    return S->numReg;
}

// stackIsFull: check is the full or no.
bool stackIsFull(STACK* S){
    
    if(size(S)<MAX)
        return false;
    
    return true;
}

// push: Add a new element to the stack.
bool push(STACK* S, TYPE element){
    
    if(stackIsFull(S))
        return false;
    printf("Adding the element %i in Stack.\n", element);
    
    S->CONTENT[S->numReg].num = element;
    S->numReg++;

    return true;
}

// pop: Remove the top element.
bool pop(STACK* S){
    
    if(size(S) == 0)
        return false;
    
    printf("Unstack: %i\n", S->CONTENT[S->numReg-1].num);

    S->CONTENT[S->numReg-1].num = -99;
    S->numReg--;

    return true;
}

// Show the top element.
void peek(STACK* S){

    if(size(S) == 0)
        printf("There is no element in stack!");
      
    printf("Top: %i\n", S->CONTENT[S->numReg-1].num);
}

// popAll: remove all elements in stack
void popAll(STACK* S){
    
    if(size(S) == 0)
        printf("The stack is already empty!");
    else{
        int i = 0;
        for(i;i< S->numReg; i++){
            printf("Unstack: %i\n", S->CONTENT[i].num);
            S->CONTENT[i].num = -99;
        }

        S->numReg = 0;
        printf("The stack is empty.\n");
    }

}

// searchInStack: search an element in the stack.
int searchStack(STACK* S, TYPE element){
    
    if(size(S)==0)
        return -2; // return -2 if stack is empty.

    int i = 0;
    for(i;i< S->numReg;i++){
        if (S->CONTENT[i].num == element)
            return i; // return the element's position.
    }

    return -1; // return -1 if element is not in the stack.

}

// showStack: show all element in the stack.
void showStack(STACK* S){
    printf("Stack: \n");

    if(S->numReg > 0){
        int i = 0;
        int top = S->numReg - 1;
        for(i;i<=top;top--){
            printf("%i\n", S->CONTENT[top].num);
        }

    }else{
        printf("There are no elements in the stack!");
    }
}

int main(){

    STACK s;

    initialize(&s);

    push(&s, 12);
    push(&s, 22);
    push(&s, 32);
    peek(&s);
    push(&s, 42);
    push(&s, 52);
    push(&s, 62);
    push(&s, 72);

    printf("Size: %i\n", size(&s));

    showStack(&s);

    pop(&s);

    showStack(&s);

    printf("Position: %i\n",searchStack(&s, 42));

    popAll(&s);

    printf("Size: %i\n", size(&s));

    showStack(&s);

    return 0;

}
