#include <iostream>
#include <vector>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(1e6)

// O(nloglogn)
vector<int> phi_1_to_n(int n) {
    vector<int> phi(n + 1);
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    return phi;
}

int pref[MAXN+10];

int32_t main()
{_
    vector<int> phi = phi_1_to_n(MAXN);
    for(int i=1; i<=MAXN; i++) pref[i] = pref[i-1] + phi[i];
    
    int t; 
    while(cin>>t && t!=0){
        cout<<pref[t]-1<<endl;
    }
    return 0;
   
}
