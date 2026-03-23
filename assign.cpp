#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Car {
    int id;
    string model;
    int price;
    int year;
    int index; // To maintain original order if necessary
};

// Custom comparator function
bool compareCars(const Car &a, const Car &b) {
    if (a.price != b.price)
        return a.price < b.price; // Ascending order of price
    if (a.year != b.year)
        return a.year > b.year; // Descending order of year
    return a.index < b.index; // Maintain original order
}

int main() {
    int N;
    cout<<"Enter number of car: ";
    cin >>N;
    vector<Car> cars(N);
    
    for (int i = 0; i < N; i++) {
        cin >> cars[i].id;
        cin.ignore();
        getline(cin, cars[i].model);
        cin >> cars[i].price >> cars[i].year;
        cars[i].index = i; // Store original order index
    }
    
    sort(cars.begin(), cars.end(), compareCars);
    
    for (const auto &car : cars) {
        cout << car.id << " " << car.model << " " << car.price << " " << car.year << endl;
    }
    
    return 0;
}
