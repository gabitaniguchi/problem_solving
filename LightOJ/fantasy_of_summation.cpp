#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  

int n, k, mod;

int fast_exp(int base, int e){
    int ans = 1;
    while(e>0){
        if(e%2==1) ans = (ans*base)%mod;
        base = (base*base)%mod;
        e = e/2;
    }
    return ans;
}

int32_t main()
{_
    int t; cin>>t;
    for(int i=1; i<=t; i++){
        cin>>n>>k>>mod;
        int sum=0;
        for(int i=1; i<=n; i++) {
            int x; cin>>x;
            sum+=x;
        }

        int ans = (((fast_exp(n, k-1))*k%mod)%mod*(sum%mod))%mod;
        cout<<"Case "<<i<<": "<<ans<<endl;
    }
   
}