#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a vehicle in the queue
typedef struct Vehicle {
    char licensePlate[15];
    struct Vehicle *next;
} Vehicle;

// Structure for a queue representing vehicles at an intersection
typedef struct Queue {
    Vehicle *front;
    Vehicle *rear;
} Queue;

// Structure for an intersection
typedef struct Intersection {
    char name[50];
    Queue vehicleQueue;
    struct Intersection *next;
} Intersection;

// Structure for a road
typedef struct Road {
    char name[50];
    Intersection *intersections;
    struct Road *next;
} Road;

// Function to create a new vehicle node
Vehicle *createVehicle(char *licensePlate) {
    Vehicle *newVehicle = (Vehicle *)malloc(sizeof(Vehicle));
    strcpy(newVehicle->licensePlate, licensePlate);
    newVehicle->next = NULL;
    return newVehicle;
}

// Function to enqueue a vehicle
void enqueue(Queue *queue, char *licensePlate) {
    Vehicle *newVehicle = createVehicle(licensePlate);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newVehicle;
        return;
    }
    queue->rear->next = newVehicle;
    queue->rear = newVehicle;
}

// Function to dequeue a vehicle
void dequeue(Queue *queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    Vehicle *temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
}

// Function to create a new intersection node
Intersection *createIntersection(char *name) {
    Intersection *newIntersection = (Intersection *)malloc(sizeof(Intersection));
    strcpy(newIntersection->name, name);
    newIntersection->vehicleQueue.front = newIntersection->vehicleQueue.rear = NULL;
    newIntersection->next = NULL;
    return newIntersection;
}

// Function to create a new road node
Road *createRoad(char *name) {
    Road *newRoad = (Road *)malloc(sizeof(Road));
    strcpy(newRoad->name, name);
    newRoad->intersections = NULL;
    newRoad->next = NULL;
    return newRoad;
}

// Function to add an intersection to a road
void addIntersection(Road *road, char *intersectionName) {
    Intersection *newIntersection = createIntersection(intersectionName);
    newIntersection->next = road->intersections;
    road->intersections = newIntersection;
}

// Function to add a road to the system
void addRoad(Road **roadList, char *roadName) {
    Road *newRoad = createRoad(roadName);
    newRoad->next = *roadList;
    *roadList = newRoad;
}

// Function to find a road by name
Road *findRoad(Road *roadList, char *roadName) {
    Road *currentRoad = roadList;
    while (currentRoad != NULL) {
        if (strcmp(currentRoad->name, roadName) == 0) {
            return currentRoad;
        }
        currentRoad = currentRoad->next;
    }
    return NULL;
}

// Function to find an intersection by name in a given road
Intersection *findIntersection(Road *road, char *intersectionName) {
    Intersection *currentIntersection = road->intersections;
    while (currentIntersection != NULL) {
        if (strcmp(currentIntersection->name, intersectionName) == 0) {
            return currentIntersection;
        }
        currentIntersection = currentIntersection->next;
    }
    return NULL;
}

// Function to display the traffic system
void displayTrafficSystem(Road *roadList) {
    Road *currentRoad = roadList;
    while (currentRoad != NULL) {
        printf("Road: %s\n", currentRoad->name);
        Intersection *currentIntersection = currentRoad->intersections;
        while (currentIntersection != NULL) {
            printf("  Intersection: %s\n", currentIntersection->name);
            Vehicle *currentVehicle = currentIntersection->vehicleQueue.front;
            while (currentVehicle != NULL) {
                printf("    Vehicle: %s\n", currentVehicle->licensePlate);
                currentVehicle = currentVehicle->next;
            }
            currentIntersection = currentIntersection->next;
        }
        currentRoad = currentRoad->next;
    }
}

// Main function with user input
int main() {
    Road *roadList = NULL;
    int choice;
    char roadName[50], intersectionName[50], licensePlate[15];

    while (1) {
        printf("\nTraffic Management System\n");
        printf("1. Add Road\n");
        printf("2. Add Intersection\n");
        printf("3. Add Vehicle\n");
        printf("4. Display Traffic System\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer

        switch (choice) {
            case 1:
                printf("Enter road name: ");
                fgets(roadName, 50, stdin);
                roadName[strcspn(roadName, "\n")] = 0; // Remove newline character
                addRoad(&roadList, roadName);
                break;
            case 2:
                printf("Enter road name: ");
                fgets(roadName, 50, stdin);
                roadName[strcspn(roadName, "\n")] = 0;
                Road *road = findRoad(roadList, roadName);
                if (road) {
                    printf("Enter intersection name: ");
                    fgets(intersectionName, 50, stdin);
                    intersectionName[strcspn(intersectionName, "\n")] = 0;
                    addIntersection(road, intersectionName);
                } else {
                    printf("Road not found!\n");
                }
                break;
            case 3:
                printf("Enter road name: ");
                fgets(roadName, 50, stdin);
                roadName[strcspn(roadName, "\n")] = 0;
                road = findRoad(roadList, roadName);
                if (road) {
                    printf("Enter intersection name: ");
                    fgets(intersectionName, 50, stdin);
                    intersectionName[strcspn(intersectionName, "\n")] = 0;
                    Intersection *intersection = findIntersection(road, intersectionName);
                    if (intersection) {
                        printf("Enter vehicle license plate: ");
                        fgets(licensePlate, 15, stdin);
                        licensePlate[strcspn(licensePlate, "\n")] = 0;
                        enqueue(&intersection->vehicleQueue, licensePlate);
                    } else {
                        printf("Intersection not found!\n");
                    }
                } else {
                    printf("Road not found!\n");
                }
                break;
            case 4:
                displayTrafficSystem(roadList);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
