#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a weather forecast
typedef struct Forecast {
    int id;
    char cityName[100];
    char date[20];
    char weatherCondition[100];
    double temperature;
    double humidity;
    struct Forecast *next;
} Forecast;

// Stack node for undo functionality
typedef struct StackNode {
    Forecast *forecast;
    struct StackNode *next;
} StackNode;

Forecast *head = NULL;
int forecastIdCounter = 1;

// Queue for incoming forecasts
typedef struct QueueNode {
    Forecast *forecast;
    struct QueueNode *next;
} QueueNode;

QueueNode *front = NULL, *rear = NULL;
StackNode *stackTop = NULL; // Stack for undo functionality

// Function to create a new forecast node
Forecast *createForecast(char *cityName, char *date, char *weatherCondition, double temperature, double humidity) {
    Forecast *newForecast = (Forecast *)malloc(sizeof(Forecast));
    newForecast->id = forecastIdCounter++;
    strcpy(newForecast->cityName, cityName);
    strcpy(newForecast->date, date);
    strcpy(newForecast->weatherCondition, weatherCondition);
    newForecast->temperature = temperature;
    newForecast->humidity = humidity;
    newForecast->next = NULL;
    return newForecast;
}

// Function to add forecast to the list
void addForecast(char *cityName, char *date, char *weatherCondition, double temperature, double humidity) {
    Forecast *newForecast = createForecast(cityName, date, weatherCondition, temperature, humidity);
    newForecast->next = head;
    head = newForecast;

    // Push to stack for undo functionality
    StackNode *newStackNode = (StackNode *)malloc(sizeof(StackNode));
    newStackNode->forecast = newForecast;
    newStackNode->next = stackTop;
    stackTop = newStackNode;

    printf("Forecast added successfully for city %s on date %s.\n", cityName, date);
}

// Function to display all forecasts
void displayForecasts() {
    if (head == NULL) {
        printf("No forecasts available.\n");
        return;
    }
    Forecast *current = head;
    printf("Weather Forecasts:\n");
    while (current != NULL) {
        printf("ID: %d, City: %s, Date: %s, Condition: %s, Temperature: %.2f°C, Humidity: %.2f%%\n",
               current->id, current->cityName, current->date, current->weatherCondition, current->temperature, current->humidity);
        current = current->next;
    }
}

// Function to search forecast by city
void searchForecastByCity(char *cityName) {
    Forecast *current = head;
    int found = 0;
    while (current != NULL) {
        if (strcmp(current->cityName, cityName) == 0) {
            printf("Forecast found for %s on %s: Condition: %s, Temperature: %.2f°C, Humidity: %.2f%%\n",
                   current->cityName, current->date, current->weatherCondition, current->temperature, current->humidity);
            found = 1;
        }
        current = current->next;
    }
    if (!found) {
        printf("No forecasts found for city: %s.\n", cityName);
    }
}

// Function to sort forecasts by temperature (ascending)
void sortForecastsByTemperature() {
    if (head == NULL || head->next == NULL) {
        return;
    }

    Forecast *i, *j;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->temperature > j->temperature) {
                // Swap the forecast data
                Forecast temp = *i;
                *i = *j;
                *j = temp;
            }
        }
    }
    printf("Forecasts sorted by temperature.\n");
}

// Function to push a forecast to the queue
void enqueueForecast(char *cityName, char *date, char *weatherCondition, double temperature, double humidity) {
    Forecast *newForecast = createForecast(cityName, date, weatherCondition, temperature, humidity);
    QueueNode *newQueueNode = (QueueNode *)malloc(sizeof(QueueNode));
    newQueueNode->forecast = newForecast;
    newQueueNode->next = NULL;

    if (rear == NULL) {
        front = rear = newQueueNode;
    } else {
        rear->next = newQueueNode;
        rear = newQueueNode;
    }
    printf("Forecast for %s added to the queue.\n", cityName);
}

// Function to dequeue a forecast from the queue
void dequeueForecast() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    QueueNode *temp = front;
    front = front->next;
    free(temp);
    printf("Forecast removed from the queue.\n");
}

// Function to undo the last forecast addition using stack
void undoLastForecast() {
    if (stackTop == NULL) {
        printf("No action to undo.\n");
        return;
    }

    StackNode *temp = stackTop;
    stackTop = stackTop->next;
    free(temp->forecast); // Free memory of the last forecast
    free(temp);
    printf("Last forecast addition undone.\n");
}

// Main function with user input
int main() {
    int choice;
    double temperature, humidity;
    char cityName[100], date[20], weatherCondition[100];

    while (1) {
        printf("\nWeather Forecasting System\n");
        printf("1. Add Forecast\n");
        printf("2. Display Forecasts\n");
        printf("3. Search Forecast by City\n");
        printf("4. Sort Forecasts by Temperature\n");
        printf("5. Add Forecast to Queue\n");
        printf("6. Remove Forecast from Queue\n");
        printf("7. Undo Last Forecast Addition\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer

        switch (choice) {
            case 1:
                printf("Enter city name: ");
                fgets(cityName, 100, stdin);
                cityName[strcspn(cityName, "\n")] = 0;
                printf("Enter date (YYYY-MM-DD): ");
                fgets(date, 20, stdin);
                date[strcspn(date, "\n")] = 0;
                printf("Enter weather condition: ");
                fgets(weatherCondition, 100, stdin);
                weatherCondition[strcspn(weatherCondition, "\n")] = 0;
                printf("Enter temperature (°C): ");
                scanf("%lf", &temperature);
                printf("Enter humidity (%%): ");
                scanf("%lf", &humidity);
                getchar();
                addForecast(cityName, date, weatherCondition, temperature, humidity);
                break;
            case 2:
                displayForecasts();
                break;
            case 3:
                printf("Enter city name to search: ");
                fgets(cityName, 100, stdin);
                cityName[strcspn(cityName, "\n")] = 0;
                searchForecastByCity(cityName);
                break;
            case 4:
                sortForecastsByTemperature();
                break;
            case 5:
                printf("Enter city name: ");
                fgets(cityName, 100, stdin);
                cityName[strcspn(cityName, "\n")] = 0;
                printf("Enter date (YYYY-MM-DD): ");
                fgets(date, 20, stdin);
                date[strcspn(date, "\n")] = 0;
                printf("Enter weather condition: ");
                fgets(weatherCondition, 100, stdin);
                weatherCondition[strcspn(weatherCondition, "\n")] = 0;
                printf("Enter temperature (°C): ");
                scanf("%lf", &temperature);
                printf("Enter humidity (%%): ");
                scanf("%lf", &humidity);
                getchar();
                enqueueForecast(cityName, date, weatherCondition, temperature, humidity);
                break;
            case 6:
                dequeueForecast();
                break;
            case 7:
                undoLastForecast();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
