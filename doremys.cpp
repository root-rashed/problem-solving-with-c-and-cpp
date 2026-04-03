#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        map<int,int> cnt;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            cnt[x]++;
        }
        
        if (cnt.size() == 1) {
            cout << "Yes\n";
        } else if (cnt.size() == 2) {
            vector<int> vals;
            for (auto& p : cnt) vals.push_back(p.second);
            sort(vals.begin(), vals.end());
            
            if (n % 2 == 0) {
                cout << (vals[0] == n/2 && vals[1] == n/2 ? "Yes" : "No") << "\n";
            } else {
                cout << (vals[0] == (n-1)/2 && vals[1] == (n+1)/2 ? "Yes" : "No") << "\n";
            }
        } else {
            cout << "No\n";
        }
    }
    
    return 0;
}