#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(1e6+10)

vector<bool> is_prime(MAXN, true);
vector<int> primes;
void crivo(){
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < MAXN; i++) {
        if(is_prime[i]) primes.push_back(i);
        if (is_prime[i] && (long long)i * i <= MAXN) {
            for (int j = i * i; j <= MAXN; j += i)
                is_prime[j] = false;
        }
    }
}

map<int,int> freq;
vector<int> v;
void init(){
    for(auto n: v){
        if(is_prime[n]){
            freq[n]=max(freq[n],(int)1);
            continue;
        }
        for(auto p: primes){
            if(p*p > n) break;
            if(n%p == 0){
                int exp=0;
                while(n%p==0) {
                    n/=p;
                    exp++;
                }
                freq[p] = max(exp, freq[p]);
            }
        }
        if(n>1) {
            freq[n]=max(freq[n],(int)1);
        }
    }
    return;
}

vector<pair<int,int>> fatora(int n){
    vector<pair<int,int>> ans;
    for(auto p: primes){
        if(p*p > n) break;
        if(n%p == 0){
            int exp=0;
            while(n%p==0) {
                n/=p;
                exp++;
            }
            ans.push_back({p, exp});
        }
    }
    if(n>1) {
        ans.push_back({n,1});
    }
    return ans;
}

int32_t main()
{_
    int n, k; cin>>n>>k;
    crivo();

    for(int i=1; i<=n; i++){
        int x; cin>>x;
        v.push_back(x);
    }

    init();
    vector<pair<int,int>> fatores = fatora(k);

    for(auto [x, exp]: fatores){
        if(freq[x]<exp){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
}
