#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter number: ";
    cin >> n;
    int start = 0, mid, ans;

    while (start <= n)
    {

        mid = start + (n - start) / 2;

        if ((mid * mid) == n)
        {
            ans = mid; // For Middle point
            break;
        }

        else if ((mid * mid) > n)
        {
            n = mid - 1; // For Left side
        }

        else
        {
            ans = mid;
            start = mid + 1; // For Right side
        }
    }

    cout << "Square root is: " << ans;
}