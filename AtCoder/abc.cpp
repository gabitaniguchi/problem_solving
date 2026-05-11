#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(1e5+10)
#define MOD 4

int exp (int base, int e){
    int ans = 1;
    while(e>0){
        if(e%2==1) ans = (ans*base)%MOD;
        base = (base*base)%MOD;
        e = e/2;

    }
    return ans%MOD;
}

int32_t main()
{_
    int a,b,c;
    cin>>a>>b>>c;

    if(a==1 || a==5 || a==6 || a==0){
        cout<<a<<endl;
        return 0;
    }
    int e = exp(b,c);
    if(e==0) e=4;
    a = a%10;

    int ans = (int)(pow(a,e))%(int)10;
    cout<<ans<<endl;
    return 0;
}