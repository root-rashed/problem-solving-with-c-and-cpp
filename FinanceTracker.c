#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a transaction
typedef struct Transaction {
    char description[50];
    float amount;
    char date[11]; // Format: YYYY-MM-DD
    struct Transaction* next;
} Transaction;

// Define a structure for a queue node (upcoming bill)
typedef struct Bill {
    char name[50];
    float amount;
    char due_date[11];
    struct Bill* next;
} Bill;

// Define a structure for a stack node (change history)
typedef struct Change {
    char action[100];
    struct Change* next;
} Change;

// Function prototypes
void addTransaction(Transaction** head, char* description, float amount, char* date);
void viewTransactions(Transaction* head);
Transaction* searchTransaction(Transaction* head, char* date);
void addBill(Bill** front, Bill** rear, char* name, float amount, char* due_date);
void viewBills(Bill* front);
void pushChange(Change** top, char* action);
void viewChanges(Change* top);

int main() {
    Transaction* transactions = NULL;
    Bill* billQueueFront = NULL;
    Bill* billQueueRear = NULL;
    Change* changeStack = NULL;

    addTransaction(&transactions, "Salary", 5000, "2025-01-01");
    addTransaction(&transactions, "Grocery", -150, "2025-01-02");
    addTransaction(&transactions, "Electricity Bill", -100, "2025-01-05");

    pushChange(&changeStack, "Added transaction: Salary $5000");
    pushChange(&changeStack, "Added transaction: Grocery -$150");
    pushChange(&changeStack, "Added transaction: Electricity Bill -$100");

    addBill(&billQueueFront, &billQueueRear, "Internet Bill", 50, "2025-01-10");
    addBill(&billQueueFront, &billQueueRear, "Credit Card Payment", 200, "2025-01-15");

    printf("Transactions:\n");
    viewTransactions(transactions);

    printf("\nUpcoming Bills:\n");
    viewBills(billQueueFront);

    printf("\nChange History:\n");
    viewChanges(changeStack);

    char searchDate[11] = "2025-01-02";
    Transaction* searchResult = searchTransaction(transactions, searchDate);
    if (searchResult) {
        printf("\nTransaction found on %s: %s $%.2f\n", searchResult->date, searchResult->description, searchResult->amount);
    } else {
        printf("\nNo transaction found on %s\n", searchDate);
    }

    return 0;
}

// Function to add a transaction
void addTransaction(Transaction** head, char* description, float amount, char* date) {
    Transaction* newTransaction = (Transaction*)malloc(sizeof(Transaction));
    strcpy(newTransaction->description, description);
    newTransaction->amount = amount;
    strcpy(newTransaction->date, date);
    newTransaction->next = *head;
    *head = newTransaction;
}

// Function to view all transactions
void viewTransactions(Transaction* head) {
    Transaction* temp = head;
    while (temp != NULL) {
        printf("%s: %s $%.2f\n", temp->date, temp->description, temp->amount);
        temp = temp->next;
    }
}

// Function to search for a transaction by date
Transaction* searchTransaction(Transaction* head, char* date) {
    Transaction* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->date, date) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to add a bill to the queue
void addBill(Bill** front, Bill** rear, char* name, float amount, char* due_date) {
    Bill* newBill = (Bill*)malloc(sizeof(Bill));
    strcpy(newBill->name, name);
    newBill->amount = amount;
    strcpy(newBill->due_date, due_date);
    newBill->next = NULL;
    if (*rear == NULL) {
        *front = *rear = newBill;
    } else {
        (*rear)->next = newBill;
        *rear = newBill;
    }
}

// Function to view all bills in the queue
void viewBills(Bill* front) {
    Bill* temp = front;
    while (temp != NULL) {
        printf("%s: %s $%.2f\n", temp->due_date, temp->name, temp->amount);
        temp = temp->next;
    }
}

// Function to push a change onto the stack
void pushChange(Change** top, char* action) {
    Change* newChange = (Change*)malloc(sizeof(Change));
    strcpy(newChange->action, action);
    newChange->next = *top;
    *top = newChange;
}

// Function to view all changes in the stack
void viewChanges(Change* top) {
    Change* temp = top;
    while (temp != NULL) {
        printf("%s\n", temp->action);
        temp = temp->next;
    }
}
