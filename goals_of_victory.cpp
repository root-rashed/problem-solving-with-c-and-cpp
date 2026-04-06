#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        long long sum = 0;
        for(int i = 0; i < n-1; i++){
            long long x; cin >> x;
            sum += x;
        }
        cout << -sum << "\n";
    }
}