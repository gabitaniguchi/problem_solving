#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(1e7+10)

char eh_primo[MAXN];
vector<int> primes;
void crivo(){
    for(int i=2; i<MAXN; i++) eh_primo[i] = 1;
    for(int i=2; i<MAXN;i++){
        if(eh_primo[i]==1) {
            primes.push_back(i);
            if((i*i < MAXN))
                for(int j=i*i; j<MAXN; j+=i) eh_primo[j] = 0;
        }
    }
}
 
int lcm(int x){
    int ans = 1;
    for(auto p:primes){
        if(p*p>x) break;
        int exp=0;
        while(x%p==0){
            x/=p;
            exp++;
        }
        if(exp>0) {
            ans*=(2*exp+1);
        }
    }
    if(x>1) ans*=3;
    return (ans+1)/2;
}
int32_t main()
{_
    int t; cin>>t;
    crivo();
    for(int i=1; i<=t; i++){
        int n; cin>>n;
        cout<<"Case "<<i<<": "<<lcm(n)<<"\n";
    }
   
}