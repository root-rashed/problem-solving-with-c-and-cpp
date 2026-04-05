#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--){
        int n, m;
        cin >> n >> m;
        string x, s;
        cin >> x >> s;
        
        // Max copies of x needed: once we have ceil(m/n)+1 copies,
        // if s hasn't appeared it never will (periodicity argument)
        int max_copies = (m / n) + 2;
        
        // Check if s can ever appear
        string big = "";
        for(int i = 0; i < max_copies; i++) big += x;
        if(big.find(s) == string::npos){
            cout << -1 << "\n";
            continue;
        }
        
        // Find minimum k: after k ops, string = x repeated 2^k times
        // Total length = n * 2^k, must be >= m
        long long copies = 1; // k=0 means 0 operations, 1 copy
        int ans = -1;
        for(int k = 0; k <= 60; k++){
            // Length of string after k ops = n * copies
            if((long long)n * copies >= m){
                // Build candidate capped at max_copies
                int use = (int)min((long long)max_copies, copies);
                string candidate = "";
                for(int i = 0; i < use; i++) candidate += x;
                if(candidate.find(s) != string::npos){
                    ans = k;
                    break;
                }
            }
            copies *= 2;
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}