#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(5e5+10)

vector<pair<pair<int,int>, int>> plan;
int v[MAXN], n,t;

int qnt(int mid){
    int quantos=0;
    for(auto [p,x]: plan){
        auto[l,r] = p;
        if(mid<l) continue;
        if(mid<r) quantos += (mid-l+1)*x;
        else quantos += (r-l+1)*x;
    }
    return quantos;
}

int busca_binaria(int &target){
    int ini = 1, fim = n, ans=n;
    while(ini<=fim){
        int mid = (ini+fim)/2;
        if(qnt(mid)<target) ini = mid+1;
        else {
            fim = mid-1;
            ans = min(ans, mid);
        }
    }
    return ans;
}

void impar(int sum){
    int idx = (sum+1)/2;
    cout<<v[busca_binaria(idx)]<<endl;
}

void par(int sum){
    int idx1 = (sum)/2;
    int idx2 = idx1+1;
    
    int resp1 = v[busca_binaria(idx1)];
    int resp2 = v[busca_binaria(idx2)];

    int ans = resp1+resp2;
    if(ans%2==0) cout<<ans/2<<endl;
    else cout<<fixed<<setprecision(1)<<ans/2.0<<endl;
}


int32_t main()
{_
    cin>>n>>t;
    for(int i=1; i<=n; i++) cin>>v[i];
    
    while(t--){
        int q;
        cin>>q;
        int sum=0;
        plan.clear();

        while(q--){
            int l,r,x;
            cin>>l>>r>>x;
            plan.push_back({{l,r},x});
            sum += (r-l+1)*x;
        }

        if(sum%2==1) impar(sum);
        else par(sum);
    }
   
}