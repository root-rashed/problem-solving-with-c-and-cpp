#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    int rollNo;
    char name[20];
    char college[40];
    float score;
};

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents;

    printf("Enter the number of students (up to %d): ", MAX_STUDENTS);
    scanf("%d", &numStudents);

    if (numStudents <= 0 || numStudents > MAX_STUDENTS) {
        printf("Invalid number of students. Exiting.\n");
        return 1;
    }

    // Input student data
    for (int i = 0; i < numStudents; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].rollNo);
        printf("Name: ");
        scanf("%s", students[i].name);  // Assuming no spaces in name
        printf("College: ");
        scanf("%s", students[i].college);  // Assuming no spaces in college name
        printf("Score: ");
        scanf("%f", &students[i].score);
    }

    // Sort students by score in descending order (Bubble Sort)
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = 0; j < numStudents - i - 1; j++) {
            if (students[j].score < students[j + 1].score) {
                // Swap
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    // Output the sorted student data
    printf("\n%-10s %-20s %-40s %-6s\n", "Roll No", "Name", "College", "Score");
    for (int i = 0; i < numStudents; i++) {
        printf("%-10d %-20s %-40s %-6.2f\n", students[i].rollNo, students[i].name, students[i].college, students[i].score);
    }

    return 0;
}
