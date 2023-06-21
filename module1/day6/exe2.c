#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void initializeArray(struct Student *students, int n, int initialRollno, const char *initialName, float initialMarks) {
    for (int i = 0; i < n; i++) {
        students[i].rollno = initialRollno;
        strcpy(students[i].name, initialName);
        students[i].marks = initialMarks;
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

    int initialRollno;
    char initialName[20];
    float initialMarks;

    printf("\nEnter initial values for the student details:\n");
    printf("Roll No: ");
    scanf("%d", &initialRollno);
    printf("Name: ");
    scanf("%s", initialName);
    printf("Marks: ");
    scanf("%f", &initialMarks);

    initializeArray(students, n, initialRollno, initialName, initialMarks);

    printf("\nInitialized Student Details:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }

    free(students);

    return 0;
}
