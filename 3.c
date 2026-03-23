#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a patient
typedef struct Patient {
    int id;
    char name[100];
    int age;
    char disease[100];
    char admissionDate[20];
    struct Patient *next;
} Patient;

Patient *head = NULL;
int patientIdCounter = 1;

// Function to create a new patient node
Patient *createPatient(char *name, int age, char *disease, char *admissionDate) {
    Patient *newPatient = (Patient *)malloc(sizeof(Patient));
    newPatient->id = patientIdCounter++;
    strcpy(newPatient->name, name);
    newPatient->age = age;
    strcpy(newPatient->disease, disease);
    strcpy(newPatient->admissionDate, admissionDate);
    newPatient->next = NULL;
    return newPatient;
}

// Function to add a patient to the list
void addPatient(char *name, int age, char *disease, char *admissionDate) {
    Patient *newPatient = createPatient(name, age, disease, admissionDate);
    newPatient->next = head;
    head = newPatient;
    printf("Patient added successfully with ID %d.\n", newPatient->id);
}

// Function to display all patients
void displayPatients() {
    if (head == NULL) {
        printf("No patients admitted.\n");
        return;
    }
    Patient *current = head;
    printf("Patients:\n");
    while (current != NULL) {
        printf("ID: %d, Name: %s, Age: %d, Disease: %s, Admission Date: %s\n",
               current->id, current->name, current->age, current->disease, current->admissionDate);
        current = current->next;
    }
}

// Function to discharge (remove) a patient by ID
void dischargePatient(int id) {
    Patient *current = head;
    Patient *previous = NULL;

    while (current != NULL) {
        if (current->id == id) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Patient with ID %d has been discharged.\n", id);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Patient with ID %d not found.\n", id);
}

// Function to update a patient's information by ID
void updatePatient(int id, char *newName, int newAge, char *newDisease, char *newAdmissionDate) {
    Patient *current = head;
    while (current != NULL) {
        if (current->id == id) {
            strcpy(current->name, newName);
            current->age = newAge;
            strcpy(current->disease, newDisease);
            strcpy(current->admissionDate, newAdmissionDate);
            printf("Patient with ID %d updated successfully.\n", id);
            return;
        }
        current = current->next;
    }
    printf("Patient with ID %d not found.\n", id);
}

// Main function with user input
int main() {
    int choice, age, id;
    char name[100], disease[100], admissionDate[20];

    while (1) {
        printf("\nHospital Patient Management System\n");
        printf("1. Add Patient\n");
        printf("2. Display Patients\n");
        printf("3. Discharge Patient\n");
        printf("4. Update Patient Information\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, 100, stdin);
                name[strcspn(name, "\n")] = 0;
                printf("Enter age: ");
                scanf("%d", &age);
                getchar();
                printf("Enter disease: ");
                fgets(disease, 100, stdin);
                disease[strcspn(disease, "\n")] = 0;
                printf("Enter admission date (YYYY-MM-DD): ");
                fgets(admissionDate, 20, stdin);
                admissionDate[strcspn(admissionDate, "\n")] = 0;
                addPatient(name, age, disease, admissionDate);
                break;
            case 2:
                displayPatients();
                break;
            case 3:
                printf("Enter patient ID to discharge: ");
                scanf("%d", &id);
                dischargePatient(id);
                break;
            case 4:
                printf("Enter patient ID to update: ");
                scanf("%d", &id);
                getchar();
                printf("Enter new name: ");
                fgets(name, 100, stdin);
                name[strcspn(name, "\n")] = 0;
                printf("Enter new age: ");
                scanf("%d", &age);
                getchar();
                printf("Enter new disease: ");
                fgets(disease, 100, stdin);
                disease[strcspn(disease, "\n")] = 0;
                printf("Enter new admission date (YYYY-MM-DD): ");
                fgets(admissionDate, 20, stdin);
                admissionDate[strcspn(admissionDate, "\n")] = 0;
                updatePatient(id, name, age, disease, admissionDate);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

