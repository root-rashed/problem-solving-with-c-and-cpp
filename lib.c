#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BOOKS 100
#define MAX_MEMBERS 100

// Structures
typedef struct {
    char name[50];
    int shelfNumber;
} Book;

typedef struct {
    char name[50];
    int serialNumber;
} Member;

// Global Variables
Book books[MAX_BOOKS];
int totalBooks = 0;

Member members[MAX_MEMBERS];
int memberCount = 0;

// Function to search for a book
void searchBook() {
    char searchName[50];
    printf("\nEnter the book name to search: ");
    getchar(); // Consume newline character from previous input
    fgets(searchName, 50, stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; // Remove trailing newline

    for (int i = 0; i < totalBooks; i++) {
        if (strcmp(books[i].name, searchName) == 0) {
            printf("Book found: %s is on shelf number %d.\n", books[i].name, books[i].shelfNumber);
            return;
        }
    }
    printf("Book not found!\n");
}

// Function to add a new member
void addMember() {
    if (memberCount < MAX_MEMBERS) {
        printf("\nEnter your name for membership: ");
        getchar(); // Consume newline character from previous input
        fgets(members[memberCount].name, 50, stdin);
        members[memberCount].name[strcspn(members[memberCount].name, "\n")] = '\0'; // Remove trailing newline
        members[memberCount].serialNumber = memberCount + 1;
        printf("Welcome, %s! Your membership serial number is %d.\n", members[memberCount].name, members[memberCount].serialNumber);
        memberCount++;
    } else {
        printf("Membership list is full!\n");
    }
}

// Function to display membership list
void displayMembers() {
    if (memberCount == 0) {
        printf("\nNo members yet.\n");
        return;
    }

    printf("\nMembership List:\n");
    for (int i = 0; i < memberCount; i++) {
        printf("%d. %s\n", members[i].serialNumber, members[i].name);
    }
}

// Function to display book list
void displayBooks() {
    if (totalBooks == 0) {
        printf("\nNo books available.\n");
        return;
    }

    printf("\nBook List:\n");
    for (int i = 0; i < totalBooks; i++) {
        printf("%d. %s (Shelf: %d)\n", i + 1, books[i].name, books[i].shelfNumber);
    }
}

// Main Menu
void menu() {
    printf("\nWelcome to the Library Management System\n");
    printf("1. Search for a Book\n");
    printf("2. Add Membership\n");
    printf("3. Display Membership List\n");
    printf("4. Display Book List\n");
    printf("5. Exit\n");
}

int main() {
    // Initialize static book data
    strcpy(books[0].name, "C Programming");
    books[0].shelfNumber = 1;
    strcpy(books[1].name, "Data Structures");
    books[1].shelfNumber = 2;
    strcpy(books[2].name, "Algorithms");
    books[2].shelfNumber = 3;
    totalBooks = 3;fclose

    int choice;
    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                searchBook();
                break;
            case 2:
                addMember();
                break;
            case 3:
                displayMembers();
                break;
            case 4:
                displayBooks();
                break;
            case 5:
                printf("\nThank you for using the Library Management System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
