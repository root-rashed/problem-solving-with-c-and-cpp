#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
 

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int b[n];
        for(int i=0; i<n; i++)
        {
            cin>>b[i];
        }
       
       
        vector<int> ans;
        ans.push_back(b[0]);
        for(int i=1; i<n;i++)
        {
            if(b[i]>=b[i-1])
            {
                ans.push_back(b[i]);
            }
            else
            {
                ans.push_back(b[i]);
                ans.push_back(b[i]);
            }
        }
        int k = ans.size();
        cout<<k<<endl;
      

      
        for(int i=0; i<k; i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}