#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t > 0)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (n == 1)
        {
            cout << "-1 -1" << "\n";
        }
        else if (n > 1)
        {
            for (int i = 0; i < n - 1; i++)
            {
                if (s[i] != s[i + 1])
                {
                    cout << i + 1 << " " << i + 2 << "\n";
                    break;
                }
            }
        }
    }

    return 0;
}
