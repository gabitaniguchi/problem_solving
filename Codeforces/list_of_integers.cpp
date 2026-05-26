#include <bits/stdc++.h>

using namespace std;
 
#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define MAXN (int)(1e6+5)
 
vector<int> primes;
vector<bool> is_prime(MAXN, true);
int x, p, k; 

void crivo(){
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < MAXN; i++) {
        if(is_prime[i]) primes.push_back(i);
        if (is_prime[i] && i * i < MAXN) {
            for (int j = i * i; j < MAXN; j += i)
                is_prime[j] = false;
        }
    }
}
 
vector<int> fatora(int n){
    vector<int> fat;
    if(is_prime[n]) {
        fat.push_back(n);
        return fat;
    }
    
    int idx=n;
    for (int d : primes) {
        if (d * d > n)
            break;
        if(n % d == 0) {
            fat.push_back(d);
            while(n % d == 0)  n /= d;
        }
    }
    if (n > 1) fat.push_back(n);
    return fat;
}

// calcula f(n,p): qnt de coprimos de p entre [1,n]
int fn(int n, vector<int> &fat){
    int ans = 0;
    for(int mask=0; mask<(1<<fat.size()); mask++){
        int temp = 1, ligado=0;
        for(int i=0; i<(fat.size()); i++){
            if(mask & (1<<i)) {
                temp *= fat[i];
                ligado++;
            }
        }
        if(ligado%2) ans-= n/temp;
        else ans+= n/temp;
    }
    return ans;
}

int solve(){
    vector<int> fat = fatora(p);
    int fnx = fn(x, fat);
    int ini=x+1, fim = (int)(1e8);
    int ans=fim;
    while(ini<=fim){
        int mid = (ini+fim)/2;

        int temp = fn(mid, fat) - fnx;
        if(temp<k) ini=mid+1;
        else {
            fim=mid-1;
            ans = min(ans, mid);
        } 
    }
    return ans;
}

int32_t main(){_
    int t; cin>>t;
    crivo();
    while(t--){
        cin>>x>>p>>k;

        cout<<solve()<<endl;
    }
    

}