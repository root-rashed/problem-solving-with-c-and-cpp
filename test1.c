#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// GLOBAL VARIABLE
#define MAX_NAME_LENGTH 50
#define MAX_PATIENTS 50

// Patient Information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char date[11];
    char condition[MAX_NAME_LENGTH];
} Patient;

Patient patients[MAX_PATIENTS];
int totalPatient = 0;

void menu();
void addPatient();
void displayPatients();
void sortPatients();
void sortByAge();
void sortByName();
void searchPatient();


//Main Function
int main() {
    menu();
    return 0;
}



void menu() {
    int choice;

    while (1) {
        printf("\nPatient Management System\n");
        printf("1. Add Patient\n");
        printf("2. Display Patients\n");
        printf("3. Search Patient\n");
        printf("4. Sort Patients\n");
        printf("5. Add Bill\n");
        printf("6. Display Bills\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline character left by scanf

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                displayPatients();
                break;
            case 3:
                searchPatient();
                break;
            case 4:
                sortPatients();
                break;
            case 5:
                // pushBill();
                break;
            case 6:
                // displayBills();
                break;
            case 7:
                printf("Exiting program.\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void addPatient() {
    if (totalPatient < MAX_PATIENTS) {
        Patient newPatient;
        printf("Enter patient name: ");
        fgets(newPatient.name, MAX_NAME_LENGTH, stdin);
        newPatient.name[strcspn(newPatient.name, "\n")] = '\0';  // Remove newline
        printf("Enter patient age: ");
        scanf("%d", &newPatient.age);
        getchar();  // Consume newline character
        printf("Enter admission date (dd/mm/yyyy): ");
        fgets(newPatient.date, 11, stdin);
        newPatient.date[strcspn(newPatient.date, "\n")] = '\0';  // Remove newline
        printf("Enter patient condition: ");
        fgets(newPatient.condition, MAX_NAME_LENGTH, stdin);
        newPatient.condition[strcspn(newPatient.condition, "\n")] = '\0';  // Remove newline

        patients[totalPatient++] = newPatient;
        printf("Patient added successfully.\n");
    } else {
        printf("Patient list is full.\n");
    }
}

void displayPatients() {
    if (totalPatient == 0) {
        printf("No patients to display.\n");
        return;
    }
    for (int i = 0; i < totalPatient; i++) {
        printf("Patient: %s, Age: %d, Date: %s, Condition: %s\n",
               patients[i].name, patients[i].age, patients[i].date, patients[i].condition);
    }
}

void searchPatient() {
    char searchName[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    fgets(searchName, MAX_NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';  // Remove newline

    int found = 0;
    for (int i = 0; i < totalPatient; i++) {
        if (strcmp(patients[i].name, searchName) == 0) {
            printf("Patient found: Name: %s, Age: %d, Date: %s, Condition: %s\n",
                   patients[i].name, patients[i].age, patients[i].date, patients[i].condition);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Patient not found.\n");
    }
}

void sortByAge() {
    for (int i = 0; i < totalPatient - 1; i++) {
        for (int j = 0; j < totalPatient - i - 1; j++) {
            if (patients[j].age > patients[j + 1].age) {
                Patient temp = patients[j];
                patients[j] = patients[j + 1];
                patients[j + 1] = temp;
            }
        }
    }
    printf("Patients list sorted by age.\n");
    displayPatients();
}

void sortByName() {
    for (int i = 0; i < totalPatient - 1; i++) {
        for (int j = 0; j < totalPatient - i - 1; j++) {
            if (strcmp(patients[j].name, patients[j + 1].name) > 0) {
                Patient temp = patients[j];
                patients[j] = patients[j + 1];
                patients[j + 1] = temp;
            }
        }
    }
    printf("Patients list sorted by name.\n");
    displayPatients();
}

void sortPatients() {
    int choice;
    printf("1. Sort patients by age.\n");
    printf("2. Sort patients by name.\n");
    printf("Choose option: ");
    scanf("%d", &choice);
    getchar();  // Consume newline character

    if (choice == 1) {
        sortByAge();
    } else if (choice == 2) {
        sortByName();
    } else {
        printf("Invalid option.\n");
    }
}
