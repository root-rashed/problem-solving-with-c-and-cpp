#include <iostream>
using namespace std;

int main() {
    long long n, m, a;
    cin >> n >> m >> a;

    long long tiles_length = (n + a - 1) / a;
    long long tiles_width  = (m + a - 1) / a;

    long long result = tiles_length * tiles_width;

    cout << result << endl;

    return 0;
}

