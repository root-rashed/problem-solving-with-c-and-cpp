#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float x, y; // Interval
    float error = 1.0;

    cout << "Enter interval (x and y): ";
    cin >> x >> y;

    if ((pow(x, 2) - x - 2) * (pow(y, 2) - y - 2) >= 0) {
        cout << "Invalid interval. The function should have opposite signs at x and y." << endl;
        return 1; // Exit with error
    }

    while (error > 0.0001) {
        float mid = (x + y) / 2;
        float f_mid = pow(mid, 2) - mid - 2;
      

        if ( f_mid < 0) { 
            y = mid;
        } else {
            x = mid;
        }

        error = abs(y - x); // Update error

        cout << "Current: x = " << x << ", y = " << y << ", Error = " << error << endl;
    }

    cout << "Approximate root: " << (x + y) / 2 << endl;
    return 0;
}
