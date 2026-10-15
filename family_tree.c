# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct Person {
    char name[50];
    int age;
    struct Person *father;
    struct Person *mother;
} Person;


Person *create_person (const char *name, int age) {
    Person *person = malloc (sizeof(Person));
        if (person == NULL) {
            printf("Memory allocation failed!\n");
        return NULL;
        }
    strcpy (person->name, name);
    person->age = age;
    person->father = NULL;
    person->mother = NULL;
    return person;
}

void read_person_info(const char *role, char *name_out, int *age_out) {
    printf("Enter %s name: ", role);
    scanf("%s", name_out);
    printf("Enter %s age: ", role);
    scanf("%d", age_out);
}

void link_parents(Person *boy, Person *father, Person *mother){
    boy->father = father;
    boy->mother = mother;
}



int main(void){
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

    read_person_info("Your",me->name, &me->age);
    read_person_info("Father's",father->name, &father->age);
    read_person_info("Mother's",mother->name, &mother->age);
    read_person_info("Parantal Grandfather's",grandfather1->name, &grandfather1->age);
    read_person_info("Parantal Grandmother's",grandmother1->name, &grandmother1->age);
    read_person_info("Maternal Grandfather's",grandfather2->name, &grandfather2->age);
    read_person_info("Maternal Grandmother's",grandmother2->name, &grandmother2->age);

    link_parents(me, father, mother);
    link_parents(father, grandfather1, grandmother1);
    link_parents(mother, grandfather2, grandmother2);


    printf("Your name is %s and age is %d\n", me->name, me->age);
    printf("Your father's name is %s and age is %d\n", father->name, father->age);
    printf("Your mother name is %s and age is %d\n", mother->name, mother->age);
    printf("Your paternal grandfather's name is %s and age is %d\n", grandfather1->name, grandfather1->age);
    printf("Your paternal grandmother's name is %s and age is %d\n", grandmother1->name, grandmother1->age);
    printf ("Your maternal grandfather's name is %s and age is %d\n",grandfather2->name, grandfather2->age);
    printf ("Your maternal grandmother's name is %s and age is %d\n",grandmother2->name, grandmother2->age);

    free(me);
    free(father);
    free(mother);
    free(grandfather1);
    free(grandfather2);
    free(grandmother1);
    free(grandmother2);
}