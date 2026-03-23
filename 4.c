#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for an order
typedef struct Order {
    int id;
    char customerName[100];
    char productName[100];
    int quantity;
    double price;
    char orderDate[20];
    struct Order *next;
} Order;

Order *head = NULL;
int orderIdCounter = 1;

// Function to create a new order node
Order *createOrder(char *customerName, char *productName, int quantity, double price, char *orderDate) {
    Order *newOrder = (Order *)malloc(sizeof(Order));
    newOrder->id = orderIdCounter++;
    strcpy(newOrder->customerName, customerName);
    strcpy(newOrder->productName, productName);
    newOrder->quantity = quantity;
    newOrder->price = price;
    strcpy(newOrder->orderDate, orderDate);
    newOrder->next = NULL;
    return newOrder;
}

// Function to add an order to the list
void addOrder(char *customerName, char *productName, int quantity, double price, char *orderDate) {
    Order *newOrder = createOrder(customerName, productName, quantity, price, orderDate);
    newOrder->next = head;
    head = newOrder;
    printf("Order added successfully with ID %d.\n", newOrder->id);
}

// Function to display all orders
void displayOrders() {
    if (head == NULL) {
        printf("No orders available.\n");
        return;
    }
    Order *current = head;
    printf("Orders:\n");
    while (current != NULL) {
        printf("ID: %d, Customer: %s, Product: %s, Quantity: %d, Price: %.2f, Order Date: %s\n",
               current->id, current->customerName, current->productName, current->quantity, current->price, current->orderDate);
        current = current->next;
    }
}

// Function to complete (remove) an order by ID
void completeOrder(int id) {
    Order *current = head;
    Order *previous = NULL;

    while (current != NULL) {
        if (current->id == id) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Order with ID %d has been completed and removed from the list.\n", id);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Order with ID %d not found.\n", id);
}

// Function to update an order by ID
void updateOrder(int id, char *newCustomerName, char *newProductName, int newQuantity, double newPrice, char *newOrderDate) {
    Order *current = head;
    while (current != NULL) {
        if (current->id == id) {
            strcpy(current->customerName, newCustomerName);
            strcpy(current->productName, newProductName);
            current->quantity = newQuantity;
            current->price = newPrice;
            strcpy(current->orderDate, newOrderDate);
            printf("Order with ID %d updated successfully.\n", id);
            return;
        }
        current = current->next;
    }
    printf("Order with ID %d not found.\n", id);
}

// Main function with user input
int main() {
    int choice, quantity, id;
    double price;
    char customerName[100], productName[100], orderDate[20];

    while (1) {
        printf("\nE-commerce Order Processing System\n");
        printf("1. Add Order\n");
        printf("2. Display Orders\n");
        printf("3. Complete Order\n");
        printf("4. Update Order\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer

        switch (choice) {
            case 1:
                printf("Enter customer name: ");
                fgets(customerName, 100, stdin);
                customerName[strcspn(customerName, "\n")] = 0;
                printf("Enter product name: ");
                fgets(productName, 100, stdin);
                productName[strcspn(productName, "\n")] = 0;
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                getchar();
                printf("Enter price: ");
                scanf("%lf", &price);
                getchar();
                printf("Enter order date (YYYY-MM-DD): ");
                fgets(orderDate, 20, stdin);
                orderDate[strcspn(orderDate, "\n")] = 0;
                addOrder(customerName, productName, quantity, price, orderDate);
                break;
            case 2:
                displayOrders();
                break;
            case 3:
                printf("Enter order ID to complete: ");
                scanf("%d", &id);
                completeOrder(id);
                break;
            case 4:
                printf("Enter order ID to update: ");
                scanf("%d", &id);
                getchar();
                printf("Enter new customer name: ");
                fgets(customerName, 100, stdin);
                customerName[strcspn(customerName, "\n")] = 0;
                printf("Enter new product name: ");
                fgets(productName, 100, stdin);
                productName[strcspn(productName, "\n")] = 0;
                printf("Enter new quantity: ");
                scanf("%d", &quantity);
                getchar();
                printf("Enter new price: ");
                scanf("%lf", &price);
                getchar();
                printf("Enter new order date (YYYY-MM-DD): ");
                fgets(orderDate, 20, stdin);
                orderDate[strcspn(orderDate, "\n")] = 0;
                updateOrder(id, customerName, productName, quantity, price, orderDate);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
