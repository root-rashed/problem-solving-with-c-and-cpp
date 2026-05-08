#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n);


    for(ll i=0; i<n; i++) 
    {
        cin>>a[i];
    }


    ll mx=INT_MIN;
    


    for(int i=0;i<n;i++)
    {
        mx=max(mx,a[(i-1+n)%n]-a[i]);
    }



    for(int i=0;i<n;i++)
    {
        mx=max(mx,a[i]-a[0]);;
    }



    for(int i=0;i<n;i++)
    {
        mx=max(mx,a[n-1]-a[i]);
    }


    
    cout<<mx<<endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}