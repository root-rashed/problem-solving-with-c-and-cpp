#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int segments = 0;
        bool inside = false;

        for (int i = 0; i < n; i++) {
            if (a[i] != 0) {
                if (!inside) {
                    segments++;
                    inside = true;
                }
            } else {
                inside = false;
            }
        }

        if (segments == 0)
            cout << 0 << '\n';
        else if (segments == 1)
            cout << 1 << '\n';
        else
            cout << 2 << '\n';
    }

    return 0;
}