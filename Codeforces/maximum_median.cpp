#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(2e5+10)
#define INF (int)(1e10+10)

int n, k; 
int v[MAXN];

bool check(int teste){
    int oper = 0;
    for(int i=((n+1)/2); i<=n; i++){
        if(teste > v[i]) oper+= (teste-v[i]);
    }
    if(oper>k) return false;
    return true;
}

int busca(int mediana){
    int i=mediana, f=INF;
    int ans=mediana;

    while(i<=f){
        int mid=(i+f)/2;

        if(check(mid)) {
            i=mid+1;
            ans = max(ans, mid);
        }
        else{
            f=mid-1;
        }
    }
    return ans;
}
int32_t main()
{_
    cin>>n>>k;

    int mediana=0;

    for(int i=1;i<=n;i++) cin>>v[i];
    sort(v+1, v+n+1);

    for(int i=1; i<=n; i++){
        if(i==((n+1)/2)) mediana = v[i];
    }

    cout<<busca(mediana)<<"\n";
}