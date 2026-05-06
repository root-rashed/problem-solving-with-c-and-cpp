#include<bits/stdc++.h>
using namespace std;
#define pb push_back

 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        int a[n],as[n];
        as[0]=0;

        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            as[i]=as[i-1]+a[i];
        }

        while(q--)
        {
            int l,r,k;
            cin>>l>>r>>k;
            int sum = as[n]-as[r]+as[l-1];
          
            if((sum+(r-l+1)*k)%2!=0)
            cout<<"YES"<<endl;
            else
            cout<<"NO"<<endl;
        }
    }
    return 0;
}