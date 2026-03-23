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

// Main function
int main() {
    Road *roadList = NULL;

    // Adding roads
    addRoad(&roadList, "Main Street");
    addRoad(&roadList, "Second Avenue");

    // Adding intersections
    addIntersection(roadList, "Main & 1st");
    addIntersection(roadList, "Main & 2nd");
    addIntersection(roadList->next, "Second & 1st");

    // Adding vehicles to queues
    enqueue(&(roadList->intersections->vehicleQueue), "ABC123");
    enqueue(&(roadList->intersections->vehicleQueue), "XYZ789");
    enqueue(&(roadList->intersections->next->vehicleQueue), "DEF456");

    // Displaying the traffic system
    displayTrafficSystem(roadList);

    return 0;
}
