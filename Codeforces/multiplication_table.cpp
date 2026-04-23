#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(1e5+10)
#define INF (int)(1e18+10)
int n, m, k;

int busca_binaria(){
    int i=1, f=n*m;
    int ans=INF;

    while(i<=f){
        int mid = (i+f)/2;
        int x=0;
        for(int i=1; i<=n; i++){
            x+= min(mid/i, m);
        }

        if(x<k) i=mid+1;
        else {
            f = mid-1;
            ans = min(ans, mid);
        }
    }
    return ans;
}

int32_t main()
{_
    cin>>n>>m>>k;
    cout<<busca_binaria()<<'\n';
}