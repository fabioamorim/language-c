#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

/*
    Insert elements;
    Delete element and return the position;
    Remove all elements in the list;
    Return the size of the list;
    Remove all elements in the list;
*/

typedef struct node{
    int value;
    struct node *next;
} NODE;

typedef NODE* pont;

typedef struct list{
    pont head;
}LIST;

void initialize(LIST *list){
    list->head = NULL;
}

int sizeOfList(LIST l){
    int size = 0;

    while(l.head!=NULL){
        size++;
        l.head = l.head->next;
    }

    return size;
}

void showAllElements(LIST l){

    printf("[ ");
    while(l.head!=NULL){
        printf("%d ", l.head->value);
        l.head = l.head->next;
    }
    printf(" ]");
}

void insertElement(LIST *l, int value){

    NODE *node = (NODE*)malloc(sizeof(NODE));
    node->value = value;
    node->next = l->head;
    l->head = node; 
}

void removeElement(LIST *l){
    if(l->head!=NULL)
        l->head = l->head->next;
}

void removeAllElements(LIST *l){
    initialize(l);
}

int findElement(LIST l, int value){

    if(l.head==NULL) return -2; // return -2 if the list is empty.

    int count = 0;

    while(l.head!=NULL){

        if(l.head->value==value) return count; // return the position.
        count++;
        l.head = l.head->next;
    }

    return -1; // return -1 if the element was not found in the list.
}

int main(){

    LIST list;

    initialize(&list);
    printf("%d\n", sizeOfList(list));
    insertElement(&list, 12);
    insertElement(&list, 13);
    printf("%d\n", sizeOfList(list));
    insertElement(&list, 22);
    insertElement(&list, 5);
    insertElement(&list, 100);
    insertElement(&list, 188);
    insertElement(&list, 199);
    insertElement(&list, 1);
    insertElement(&list, 23);
    insertElement(&list, 90);

    showAllElements(list);

    removeElement(&list);

    printf("\n\n");

    showAllElements(list);

    removeElement(&list);

    printf("\n\n");

    showAllElements(list);

    printf("\n\n");

    //removeAllElements(&list);

    removeElementByValue(&list, 1999);

    return 0;
}