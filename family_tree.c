#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person { 
    char name[50]; 
    int age; 
    struct Person *father; 
    struct Person *mother; 
} Person;

void link_parents(Person *boy, Person *father, Person *mother) {
    boy->father = father;
    boy->mother = mother;
}

Person *create_person(const char *name, int age) {
    Person *person = malloc(sizeof(Person));
    if (person == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    strcpy(person->name, name);
    person->age = age;
    person->father = NULL;
    person->mother = NULL;
    return person;
}

int main() { 

    Person *me = create_person("Pankaj", 19);
    Person *father = create_person("Binod", 45);
    Person *mother = create_person("Gita", 42);
    Person *grandfather1 = create_person("Bhuneswar", 71);
    Person *grandmother1 = create_person("Dhaneswari", 68);
    Person *grandfather2 = create_person("Ramsahay", 75);
    Person *grandmother2 = create_person("Sila", 72);

    if (me == NULL || father == NULL || mother == NULL || grandfather1 == NULL || grandmother1 == NULL || grandfather2 == NULL || grandmother2 == NULL) {
        printf("Memory allocation failed! \n");
        return 1;
    }


    // Person grandparent1 = {"Dhaneswari", 68, NULL, NULL}; 
    // Person grandparent2 = {"Bhuneswar", 71, NULL, NULL};
    // Person grandparent3 = {"Sila", 72, NULL, NULL};
    // Person grandparent4 = {"Ramsahay", 75, NULL, NULL};
    // Person parent1 = {"Binod", 45, &grandparent1, &grandparent2}; 
    // Person parent2 = {"Gita", 42, &grandparent3, &grandparent4}; 
    // Person boy = {"Pankaj", 19, &parent1, &parent2}; 

    // printf("boy's name: %s\n", boy.name); 
    // printf("boy's age: %d\n", boy.age); 
    // printf("Father's name: %s\n", boy.father->name); 
    // printf("Mother's name: %s\n", boy.mother->name); 
    // printf("Grandfather's name: %s\n", boy.father->father->name); 
    // printf("Grandmother's name: %s\n", boy.father->mother->name);
    // printf("Maternal Grandfather's name: %s\n", boy.mother->father->name);
    // printf("Maternal Grandmother's name: %s\n", boy.mother->mother->name);

    link_parents(me, father, mother);
    link_parents(father, grandfather1, grandmother1);
    link_parents(mother, grandfather2, grandmother2);

    printf("My name is %s and my age is %d\n", me->name, me->age);
    printf("My Father's name is %s and age is %d\n",father->name, father->age);
    printf("My Mother's name is %s and age is %d\n", mother->name, mother->age);
    printf("My Grandfather's name is %s and age is %d\n", grandfather1->name, grandfather1->age);
    printf("My Grandmother's name is %s and age is %d\n", grandmother1->name, grandmother1->age);
    printf("My Maternal Grandfather's name is %s and age is %d\n", grandfather2->name, grandfather2->age);
    printf("My Maternal Grandmother's name is %s and age is %d\n", grandmother2->name, grandmother2->age);


    free(me);
    free(father);
    free(mother);
    free(grandfather1);
    free(grandfather2);
    free(grandmother1);
    free(grandmother2);

    return 0; 
}

