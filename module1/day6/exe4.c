#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

int compare(const void *a, const void *b) {
    const struct Student *studentA = (const struct Student *)a;
    const struct Student *studentB = (const struct Student *)b;

    // Sort in descending order based on marks
    if (studentA->marks > studentB->marks) {
        return -1;
    } else if (studentA->marks < studentB->marks) {
        return 1;
    }

    return 0;
}

void sortArray(struct Student *students, int n) {
    qsort(students, n, sizeof(struct Student), compare);
}

void displayArray(const struct Student *students, int n) {
    for (int i = 0; i < n; i++) {
        printf("Student %d\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
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

    printf("\nBefore Sorting:\n");
    displayArray(students, n);

    sortArray(students, n);

    printf("\nAfter Sorting:\n");
    displayArray(students, n);

    free(students);

    return 0;
}
