#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a task
typedef struct Task {
    int id;
    char description[100];
    char dueDate[20];
    int priority;
    struct Task *next;
} Task;

Task *head = NULL;
int taskIdCounter = 1;

// Function to create a new task node
Task *createTask(char *description, char *dueDate, int priority) {
    Task *newTask = (Task *)malloc(sizeof(Task));
    newTask->id = taskIdCounter++;
    strcpy(newTask->description, description);
    strcpy(newTask->dueDate, dueDate);
    newTask->priority = priority;
    newTask->next = NULL;
    return newTask;
}

// Function to add a task to the list
void addTask(char *description, char *dueDate, int priority) {
    Task *newTask = createTask(description, dueDate, priority);
    newTask->next = head;
    head = newTask;
    printf("Task added successfully with ID %d.\n", newTask->id);
}

// Function to display all tasks
void displayTasks() {
    if (head == NULL) {
        printf("No tasks available.\n");
        return;
    }
    Task *current = head;
    printf("Tasks:\n");
    while (current != NULL) {
        printf("ID: %d, Description: %s, Due Date: %s, Priority: %d\n", current->id, current->description, current->dueDate, current->priority);
        current = current->next;
    }
}

// Function to complete (remove) a task by ID
void completeTask(int id) {
    Task *current = head;
    Task *previous = NULL;
    
    while (current != NULL) {
        if (current->id == id) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Task with ID %d completed and removed from the list.\n", id);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Task with ID %d not found.\n", id);
}

// Function to update a task by ID
void updateTask(int id, char *newDescription, char *newDueDate, int newPriority) {
    Task *current = head;
    while (current != NULL) {
        if (current->id == id) {
            strcpy(current->description, newDescription);
            strcpy(current->dueDate, newDueDate);
            current->priority = newPriority;
            printf("Task with ID %d updated successfully.\n", id);
            return;
        }
        current = current->next;
    }
    printf("Task with ID %d not found.\n", id);
}

// Main function with user input
int main() {
    int choice, id, priority;
    char description[100], dueDate[20];

    while (1) {
        printf("\nTask Scheduler\n");
        printf("1. Add Task\n");
        printf("2. Display Tasks\n");
        printf("3. Complete Task\n");
        printf("4. Update Task\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer

        switch (choice) {
            case 1:
                printf("Enter description: ");
                fgets(description, 100, stdin);
                description[strcspn(description, "\n")] = 0;
                printf("Enter due date (YYYY-MM-DD): ");
                fgets(dueDate, 20, stdin);
                dueDate[strcspn(dueDate, "\n")] = 0;
                printf("Enter priority (1-5): ");
                scanf("%d", &priority);
                getchar();
                addTask(description, dueDate, priority);
                break;
            case 2:
                displayTasks();
                break;
            case 3:
                printf("Enter task ID to complete: ");
                scanf("%d", &id);
                completeTask(id);
                break;
            case 4:
                printf("Enter task ID to update: ");
                scanf("%d", &id);
                getchar();
                printf("Enter new description: ");
                fgets(description, 100, stdin);
                description[strcspn(description, "\n")] = 0;
                printf("Enter new due date (YYYY-MM-DD): ");
                fgets(dueDate, 20, stdin);
                dueDate[strcspn(dueDate, "\n")] = 0;
                printf("Enter new priority (1-5): ");
                scanf("%d", &priority);
                getchar();
                updateTask(id, description, dueDate, priority);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
