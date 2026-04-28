#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(3e9+10)

vector<int> primes;
void segmentedSieve() {
    // generate all primes up to sqrt(R)
    int lim = sqrt(MAXN);
    vector<char> mark(lim + 1, false);
    for (int i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }
}

int countPrimes(int L, int R){
    vector<char> isPrime(R - L + 1, true);
    for (int i : primes){
        if(i*i>R) break;
        for (int j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
        isPrime[j - L] = false;
    }
    if (L == 1) isPrime[0] = false;
    
    int qnt=0;
    for(int i=0; i<=R-L; i++) if(isPrime[i]) qnt++;
    return qnt;
}

int32_t main()
{_
    segmentedSieve();

    int t; cin>>t;
    for(int i=1;i<=t;i++){
        int l,r; cin>>l>>r;

        int ans = countPrimes(l,r);
        
        cout<<"Case "<<i<<": "<<ans<<endl;
    }
   
}