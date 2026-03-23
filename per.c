#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Expense {
    char description[100];
    double amount;
    struct Expense *next;
} Expense;

typedef struct StackNode {
    Expense *expense;
    struct StackNode *next;
} StackNode;

typedef struct Stack {
    StackNode *top;
} Stack;

Expense *head = NULL;
Stack undoStack, redoStack;

// Function to create a new expense node
Expense *createExpense(char *description, double amount) {
    Expense *newExpense = (Expense *)malloc(sizeof(Expense));
    strcpy(newExpense->description, description);
    newExpense->amount = amount;
    newExpense->next = NULL;
    return newExpense;
}

// Function to add an expense
void addExpense(char *description, double amount) {
    Expense *newExpense = createExpense(description, amount);
    newExpense->next = head;
    head = newExpense;

    // Push to undo stack
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    newNode->expense = newExpense;
    newNode->next = undoStack.top;
    undoStack.top = newNode;

    // Clear redo stack on new action
    redoStack.top = NULL;
}

// Function to push to stack
void push(Stack *stack, Expense *expense) {
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    newNode->expense = expense;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop from stack
Expense *pop(Stack *stack) {
    if (stack->top == NULL) return NULL;
    StackNode *temp = stack->top;
    Expense *expense = temp->expense;
    stack->top = stack->top->next;
    free(temp);
    return expense;
}

// Function to perform undo
void undo() {
    if (undoStack.top == NULL) {
        printf("Nothing to undo.\n");
        return;
    }
    Expense *expense = pop(&undoStack);
    head = head->next;

    push(&redoStack, expense);
    printf("Undo: Removed expense '%s' of amount %.2f.\n", expense->description, expense->amount);
}

// Function to perform redo
void redo() {
    if (redoStack.top == NULL) {
        printf("Nothing to redo.\n");
        return;
    }
    Expense *expense = pop(&redoStack);
    expense->next = head;
    head = expense;

    push(&undoStack, expense);
    printf("Redo: Restored expense '%s' of amount %.2f.\n", expense->description, expense->amount);
}

// Function to display expenses
void displayExpenses() {
    if (head == NULL) {
        printf("No expenses recorded.\n");
        return;
    }
    Expense *current = head;
    printf("Expenses:\n");
    while (current != NULL) {
        printf(" - %s: %.2f\n", current->description, current->amount);
        current = current->next;
    }
}

// Main function with user input
int main() {
    int choice;
    char description[100];
    double amount;

    // Initialize stacks
    undoStack.top = NULL;
    redoStack.top = NULL;

    while (1) {
        printf("\nPersonal Expense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. Undo\n");
        printf("3. Redo\n");
        printf("4. Display Expenses\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer

        switch (choice) {
            case 1:
                printf("Enter description: ");
                fgets(description, 100, stdin);
                description[strcspn(description, "\n")] = 0;
                printf("Enter amount: ");
                scanf("%lf", &amount);
                getchar();
                addExpense(description, amount);
                break;
            case 2:
                undo();
                break;
            case 3:
                redo();
                break;
            case 4:
                displayExpenses();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
