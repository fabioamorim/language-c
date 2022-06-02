#include <stdio.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int value;
}REGISTER;

typedef struct{
    REGISTER list[MAX];
    int nrElem;
}LISTA;

void initialize(LISTA* l){
    l->nrElem = 0;
}

int searchElement(LISTA* l, int reg){

    if(l->nrElem==0) return -1;

    for(int i=0;i<l->nrElem;i++)
        if(l->list[i].value == reg)
            return i;

    return -1;
}

bool addElement(LISTA* l, REGISTER reg){

    if((l->nrElem+1)==MAX) 
        return false;

    l->list[l->nrElem].value = reg.value;
    l->nrElem++;

    return true;

}

bool addElementPosition(LISTA* l, REGISTER reg, int pos){
    
    if((l->nrElem+1)==MAX || pos > l->nrElem) 
        return false;

    for(int i = l->nrElem;i>=pos;i--)
        l->list[i+1].value = l->list[i].value;

    l->list[pos].value = reg.value;
    l->nrElem++;

    return true;
}

bool deleteElement(LISTA* l, REGISTER reg){

    if(l->nrElem==0)
        return false;

    int pos;
    pos = searchElement(l, reg.value);

    if(pos == -1)
        return false;

    for(int i = pos; pos<l->nrElem;pos++){
        l->list[pos].value = l->list[pos+1].value;
    }
    l->nrElem--;
    return true;
}

bool deleteElementPosition(LISTA* l, int pos){
    
    if(l->nrElem==0 || pos > l->nrElem)
        return false;

    for(int i = pos;pos<=l->nrElem;pos++)
        l->list[pos].value = l->list[pos+1].value;

    l->nrElem--;
    return true;

}

void showList(LISTA* l){

    if(l->nrElem==0)
        printf("The list is empty!\n");
    else{
        printf("Elements in the list: \n");
        for(int i = 0;i<l->nrElem;i++)
            printf("%d\n",l->list[i].value);

        printf("End of the list.\n");
    }
}

int main(){

    LISTA l;
    initialize(&l);

    REGISTER r1;
    REGISTER r2;
    REGISTER r3;
    REGISTER r4;
    REGISTER r5;
    REGISTER r6;

    r1.value = 20;
    r2.value = 23;
    r3.value = 44;
    r4.value = 2;
    r5.value = 3;
    r6.value = 8;

    addElement(&l, r1);
    addElement(&l, r2);
    addElement(&l, r3);
    addElement(&l, r4);
    addElement(&l, r5);
    addElement(&l, r6);

    //showList(&l);

    //printf("%d", searchElement(&l, 100));

    REGISTER rtest;
    rtest.value = 100;

    //deleteElement(&l, r2);

    //showList(&l);

    addElementPosition(&l, rtest, 7);

    showList(&l);

    deleteElementPosition(&l, 5);

    showList(&l);

    return 0;
}