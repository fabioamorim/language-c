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

void insertInHead(LIST *l, int value){

    NODE *node = (NODE*)malloc(sizeof(NODE));
    node->value = value;
    node->next = l->head;
    l->head = node; 
}

void insertInTail(LIST *l, int value){

    NODE *node = (NODE*)malloc(sizeof(NODE));
    struct list p = *l;

    node->value = value;
    node->next = NULL;

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

    insertInHead(&list, 12);
    insertInHead(&list, 13);
    insertInHead(&list, 22);
    insertInHead(&list, 33);

    showAllElements(list);

    printf("\n\n");

    insertInTail(&list, 200);

    showAllElements(list);

    return 0;
}