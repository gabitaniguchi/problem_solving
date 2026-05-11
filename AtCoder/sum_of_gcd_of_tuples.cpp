#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(1e5+10)
#define MOD (int)(1e9+7)

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
    int n, k;
    cin>>n>>k;

    int ans = 0;
    vector<int> qnt(k+10);

    for(int i=k; i>=1; i--){
        qnt[i] = exp(k/i, n);

        for(int j=2*i; j<=k; j+=i){
            qnt[i] = (qnt[i] - qnt[j] + MOD)%MOD;
        }

        ans = ((qnt[i]*i)%MOD + ans)%MOD;
    }

    cout<<ans<<endl;
}

