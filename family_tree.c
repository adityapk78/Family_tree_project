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

void print_family_relationships(const Person *person){
    if (person == NULL){
        printf("Person is NULL\n");
    } else{
        printf("\nName: %s, and Age: %d\n", person->name, person->age);
    }
    if (person->father != NULL){
        printf("Father's Name: %s, and Age: %d\n", person->father->name, person->father->age);
    } else{
        printf("Father's data is not available!\n");
    }
    if (person->mother != NULL){
        printf("Mother's Name: %s, and Age: %d\n", person->mother->name, person->mother->age);
    } else{
        printf("Mother's data is not available!\n");
    }
}



int main(void){
    char name [50];
    int age;
    Person *me = create_person(name, age);
    Person *father = create_person(name, age);
    Person *mother = create_person(name, age);
    Person *grandfather1 = create_person(name,age);
    Person *grandmother1 = create_person(name,age);
    Person *grandfather2 = create_person(name,age);
    Person *grandmother2 = create_person(name,age);

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

    print_family_relationships(me);
    print_family_relationships(father);
    print_family_relationships(mother);

    free(me);
    free(father);
    free(mother);
    free(grandfather1);
    free(grandfather2);
    free(grandmother1);
    free(grandmother2);
}