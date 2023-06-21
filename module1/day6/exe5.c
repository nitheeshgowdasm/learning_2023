#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

int searchArray(const struct Student *students, int n, const char *targetName) {
    for (int i = 0; i < n; i++) {
        if (strcmp(students[i].name, targetName) == 0) {
            return i; // Return the index of the found student
        }
    }

    return -1; // Return -1 if the student is not found
}

int main() {
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 0;
    }

    printf("\nEnter the student details:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].rollno);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
        printf("\n");
    }

    char targetName[20];
    printf("Enter the name of the student to search: ");
    scanf("%s", targetName);

    int foundIndex = searchArray(students, n, targetName);

    if (foundIndex != -1) {
        printf("\nStudent found at index %d\n", foundIndex);
        printf("Roll No: %d\n", students[foundIndex].rollno);
        printf("Name: %s\n", students[foundIndex].name);
        printf("Marks: %.2f\n", students[foundIndex].marks);
    } else {
        printf("\nStudent not found.\n");
    }

    free(students);

    return 0;
}
