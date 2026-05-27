#include <bits/stdc++.h>

using namespace std;
 
#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define MAXN (int)(5e6+5)
#define MOD 998244353

vector<int> phi(MAXN), s(MAXN);

int exp (int base, int e){
    int ans = 1;
 
    while(e>0){
        if(e%2==1) ans = (ans*base)%MOD;
        base = (base*base)%MOD;
        e = e/2;
    }
 
    return ans;
}

// O(nloglogn)
void phi_precomp() {
    for (int i = 0; i <MAXN; i++)
        phi[i] = i;
 
    for (int i = 2; i < MAXN; i++) {
        if (phi[i] == i) {
            for (int j = i; j < MAXN; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    for(int i=1; i<MAXN; i++){
        s[i] = (s[i-1] + phi[i])%MOD;
    }
}

map<int, int> s_memo;
int inv = exp(2, MOD-2);

int get_s(int n){
    if(s_memo[n]!=0) return s_memo[n];
    if(n<MAXN) return s[n];

    int sn = (((n%MOD)*(n+1)%MOD)%MOD*inv)%MOD;
    int temp = 0;
    for(int q=2; q<=n; q++){
        int l=q;
        int v = n/l;
        int r=n/v;

        temp = (temp%MOD + (r-l+1)%MOD*get_s(n/q)%MOD)%MOD;
        q = r;
    }

    s_memo[n] = (sn - temp + MOD)%MOD;
    return s_memo[n];
}

void solve(int n){
    phi_precomp();
    int sub=0;
    cout<<get_s(n)<<endl;
}

int32_t main(){_
    int n; cin>>n;
    solve(n);
}
