#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

/*
    Insert element in the head;
    Insert element in the tail;
    Remove element in the head;
    Remove element in the tail;
    Remove all elements in the list;
    Return the size of the list;
    Return the position of element is searching.
*/

typedef struct node{
    int value;
    struct node *next;
} NODE;

typedef NODE* pont;

typedef struct list{
    pont head; // the first element in the list
    pont tail; // the last element in the list
}LIST;

void initialize(LIST *l){
    l->tail = NULL;
    l->head = NULL;
}

int sizeOfList(LIST l){
    int size = 0;

    if (l.head==NULL) return size;

    while(l.head!=NULL){
        size++;
        l.head = l.head->next;
    }

    return size;
}

void showAllElements(LIST l){
    
    if(sizeOfList(l)==0)
        printf("The list is empty!");
    else{
       
        printf("[ ");    
       
        while(l.head!=NULL){
            printf("%d ", l.head->value);
         l.head = l.head->next;
        }
        
        printf(" ]");

    }
}

void insertInHead(LIST *l, int value){

    NODE *node = (NODE*)malloc(sizeof(NODE));
    node->value = value;

    if(sizeOfList(*l)==0){
        l->tail = node;
        l->tail->next = NULL;
        l->head = l->tail;
    }else{
        node->next = l->head;
        l->head = node;
    }
}

void insertInTail(LIST *l, int value){

    LIST p = *l;
    NODE *node = (NODE*)malloc(sizeof(NODE));

    node->value = value;

    while(p.head!=NULL){
        if(p.head->next==p.tail){
            p.head->next = p.tail;
            l->tail = node;
            l->tail->next = NULL;
            p.head->next->next = l->tail;
            break;
        }
        p.head = p.head->next;
    }

}

void removeElementInHead(LIST *l){
    if(l->head!=NULL)
        l->head = l->head->next;
}

void removeElementInTail(LIST *l){
    LIST p = *l;

    while(p.head!=NULL){
        if(p.head->next==p.tail){
            p.tail = p.head;
            p.tail->next = NULL;
            l->tail = p.tail;
            break;
        }
        p.head = p.head->next;
    }
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
    showAllElements(list);
    printf("\n");
    printf("Size of list: %d\n", sizeOfList(list));

    insertInHead(&list, 12);
    showAllElements(list);
    printf("\n");
    printf("Size of list: %d\n", sizeOfList(list));
    
    insertInHead(&list, 13);
    showAllElements(list);
    printf("\n");
    printf("Size of list: %d\n", sizeOfList(list));

    insertInHead(&list, 22);
    showAllElements(list);
    printf("\n");
    printf("Size of list: %d\n", sizeOfList(list));

    insertInHead(&list, 33);
    //insertInTail(&list, 88);
    showAllElements(list);
    printf("\n");
    printf("Size of list: %d\n", sizeOfList(list));

    insertInTail(&list, 88);
    showAllElements(list);
    printf("\n");
    printf("Size of list: %d\n", sizeOfList(list));

    removeElementInHead(&list);
    showAllElements(list);
    printf("\n");
    printf("Size of list: %d\n", sizeOfList(list));

    removeElementInTail(&list);
    showAllElements(list);
    printf("\n");
    printf("Size of list: %d\n", sizeOfList(list));
    
    return 0;
}