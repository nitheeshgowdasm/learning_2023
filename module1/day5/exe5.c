#include <stdio.h>
#include <string.h>

struct Person {
    char name[50];
    int age;
};

void swapFields(struct Person *person1, struct Person *person2) {
    char tempName[50];
    strcpy(tempName, person1->name);
    strcpy(person1->name, person2->name);
    strcpy(person2->name, tempName);

    int tempAge = person1->age;
    person1->age = person2->age;
    person2->age = tempAge;
}

int main() {
    struct Person person1, person2;

    printf("Enter details for Person 1:\n");
    printf("Name: ");
    scanf("%s", person1.name);
    printf("Age: ");
    scanf("%d", &person1.age);

    printf("\nEnter details for Person 2:\n");
    printf("Name: ");
    scanf("%s", person2.name);
    printf("Age: ");
    scanf("%d", &person2.age);

    printf("\nBefore swapping:\n");
    printf("Person 1:\nName: %s, Age: %d\n", person1.name, person1.age);
    printf("Person 2:\nName: %s, Age: %d\n", person2.name, person2.age);

    swapFields(&person1, &person2);

    printf("\nAfter swapping:\n");
    printf("Person 1:\nName: %s, Age: %d\n", person1.name, person1.age);
    printf("Person 2:\nName: %s, Age: %d\n", person2.name, person2.age);

    return 0;
}
