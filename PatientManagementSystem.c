#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// GLOBAL VARIABLE
#define MAX_NAME_LENGTH 50


// CREATE NODE
typedef struct Patient {
    char name[MAX_NAME_LENGTH];
    int age;
    char date[11];
    char condition[MAX_NAME_LENGTH];
    struct Patient *next;
} Patient;

typedef struct Bill {
    char name[MAX_NAME_LENGTH];
    float amount;
    struct Bill *next;
} Bill;


Patient *head = NULL;
Bill *billHead = NULL;

Patient* createPatient(char *name, int age, char *date, char *condition) {
    Patient *newPatient = (Patient *)malloc(sizeof(Patient));
    strcpy(newPatient->name, name);
    newPatient->age = age;
    strcpy(newPatient->date, date);
    strcpy(newPatient->condition, condition);
    newPatient->next = NULL;
    return newPatient;
}

void addPatient() {
    char name[MAX_NAME_LENGTH], date[11], condition[MAX_NAME_LENGTH];
    int age;
    printf("Enter patient name: ");
    scanf(" %[^\n]", name);
    printf("Enter age: ");
    scanf("%d", &age);
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", date);
    printf("Enter condition: ");
    scanf(" %[^\n]", condition);
    
    Patient *newPatient = createPatient(name, age, date, condition);
    if (head == NULL) {
        head = newPatient;
    } else {
        Patient *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newPatient;
    }
}

void displayPatients() {
    if (head == NULL) {
        printf("No patients found.\n");
        return;
    }
    Patient *temp = head;
    printf("Patient Details:\n");
    while (temp != NULL) {
        printf("Name: %s, Age: %d, Date: %s, Condition: %s\n", temp->name, temp->age, temp->date, temp->condition);
        temp = temp->next;
    }
}

Patient* searchPatient(char *name) {
    Patient *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void sortPatients() {
    if (head == NULL || head->next == NULL) {
        return;
    }
    Patient *i, *j;
    char tempName[MAX_NAME_LENGTH], tempDate[11], tempCondition[MAX_NAME_LENGTH];
    int tempAge;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (strcmp(i->name, j->name) > 0) {
                strcpy(tempName, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, tempName);

                tempAge = i->age;
                i->age = j->age;
                j->age = tempAge;

                strcpy(tempDate, i->date);
                strcpy(i->date, j->date);
                strcpy(j->date, tempDate);

                strcpy(tempCondition, i->condition);
                strcpy(i->condition, j->condition);
                strcpy(j->condition, tempCondition);
            }
        }
    }
}

Bill* createBill(char *name, float amount) {
    Bill *newBill = (Bill *)malloc(sizeof(Bill));
    strcpy(newBill->name, name);
    newBill->amount = amount;
    newBill->next = NULL;
    return newBill;
}

void pushBill() {
    char name[MAX_NAME_LENGTH];
    float amount;
    printf("Enter patient name for bill: ");
    scanf(" %[^\n]", name);
    printf("Enter bill amount: ");
    scanf("%f", &amount);

    Bill *newBill = createBill(name, amount);
    newBill->next = billHead;
    billHead = newBill;
}

void displayBills() {
    if (billHead == NULL) {
        printf("No bills found.\n");
        return;
    }
    Bill *temp = billHead;
    printf("Bills:\n");
    while (temp != NULL) {
        printf("Name: %s, Amount: %.2f\n", temp->name, temp->amount);
        temp = temp->next;
    }
}


// MAIN FUNCTION
int main() {
    int choice;
    char searchName[MAX_NAME_LENGTH];

    //OPTIONS    
    do {
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
        
        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                displayPatients();
                break;
            case 3:
                printf("Enter name to search: ");
                scanf(" %[^\n]", searchName);
                Patient *searched = searchPatient(searchName);
                if (searched != NULL) {
                    printf("Patient found: Name: %s, Age: %d, Date: %s, Condition: %s\n",
                           searched->name, searched->age, searched->date, searched->condition);
                } else {
                    printf("Patient not found.\n");
                }
                break;
            case 4:
                sortPatients();
                printf("Patients sorted by name.\n");
                break;
            case 5:
                pushBill();
                break;
            case 6:
                displayBills();
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
