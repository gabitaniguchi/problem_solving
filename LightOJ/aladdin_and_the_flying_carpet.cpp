#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(1e6+10)

int eh_primo[MAXN];
vector<int> primes;
void crivo(){
    for(int i=2; i<MAXN; i++) eh_primo[i] = 1;
    for(int i=2; i<MAXN;i++){
        if(eh_primo[i]) {
            primes.push_back(i);
            if((i*i < MAXN))
                for(int j=i*i; j<MAXN; j+=i) eh_primo[j] = 0;
        }
    }
}
 
int count_divisors(int x){
    int div=1;
    for(auto p:primes){
        if(p*p>x) break;
        int exp=0;
        while(x%p==0){
            x/=p;
            exp++;
        }
        if(exp>0) div*=(exp+1);
    }
    if(x>1) div*=2;
    return div;
}

int32_t main()
{_
    int t; cin>>t;
    crivo();
    for(int i=1; i<=t; i++){
        int a,b; cin>>a>>b;
        int ans; 
        if(b*b>a) ans=0;
        else{
            int div = count_divisors(a);
            div/=2;

            for(int j=1; j<b;j++) {
                if(a%j==0) div--;
            }
            ans=div;
        }
   
        cout<<"Case "<<i<<": "<<ans<<endl;
    }
   
}