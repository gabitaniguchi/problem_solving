#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(1e5+10)

int32_t main()
{_
    int t; cin>>t;
    for(int i=1; i<=t;i++){
        int n; cin>>n;
        int q = sqrt(n);
        int dq = sqrt(n/2);

        int ans = n-q-dq;
        cout<<"Case "<<i<<": "<<ans<<endl;
    }
   
}