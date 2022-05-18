#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person
{
    char name[10];
    int age;
};

void showPerson(struct Person person)
{
    printf("Name: %s\n", person.name);
    printf("Age: %i", person.age);
}

int main()
{
    struct Person person;
    strcpy(person.name, "Fabio");
    person.age = 34;

    showPerson(person);

    return 0;
    
}