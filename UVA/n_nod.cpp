#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(1e6+10)
#define MAXI (int)(64726)
int divisores[MAXN], dp[MAXI];

// O(N log N)
void init(){
    for (int i = 1; i < MAXN; ++i) {
        for (int j = i; j < MAXN; j += i) {
            divisores[j]++;
        }
    }
    
    dp[0] = 1;
    for(int i=1; i<MAXI; i++){
        dp[i] = dp[i-1] + divisores[dp[i-1]];
    }
}

// retorna quantos numeros em dp tal que dp[ans] <= target
int busca(int target){
    int l=0, r=MAXI-1;
    int ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(dp[mid]>target) r=mid-1;
        else{
            ans = max(ans, mid);
            l=mid+1;
        }
    }
    return ans+1;
}


int32_t main(){
    int dp[MAXN];
    init();

    int t; cin>>t;
    for(int i=1;i<=t;i++){
        int a,b; 
        cin>>a>>b;
        int resp = busca(b) - busca(a-1);
        cout<<"Case "<<i<<": "<<resp<<endl;
    }

    return 0;
}