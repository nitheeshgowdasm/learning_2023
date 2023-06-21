#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void initializeArray(struct Student *students, int n, const char *input) {
    char tempName[20];
    float tempMarks;
    int tempRollno;

    int count = sscanf(input, "%d %s %f", &tempRollno, tempName, &tempMarks);

    if (count == 3) {
        students[0].rollno = tempRollno;
        strcpy(students[0].name, tempName);
        students[0].marks = tempMarks;
    } else {
        printf("Invalid input format.\n");
        return;
    }

    for (int i = 1; i < n; i++) {
        input = strchr(input, '\0') + 1;
        count = sscanf(input, "%d %s %f", &tempRollno, tempName, &tempMarks);

        if (count == 3) {
            students[i].rollno = tempRollno;
            strcpy(students[i].name, tempName);
            students[i].marks = tempMarks;
        } else {
            printf("Invalid input format.\n");
            return;
        }
    }
}

int main() {
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);
    getchar(); // Clear the newline character from the input buffer

    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 0;
    }

    char input[100];
    printf("Enter the student details:\n");

    for (int i = 0; i < n; i++) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove trailing newline character

        initializeArray(&students[i], 1, input);
    }

    printf("\nStudent Details:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }

    free(students);

    return 0;
}
