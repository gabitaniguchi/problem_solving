#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(1e5+10)
#define INF (int)(1e18)

int P,C;
vector<int> p, c;
set<int> opt;

pair<int,int> solve(){
    if(P==0) return {0, 0};
    else if(C==0) return {p[P-1], 0};
    else if(p[P-1] <= c[0]) return {p[P-1], 0};

    pair<int, int> ans;
    ans = {0, INF};

    for(auto x: opt){
        int angry=0;

        //busca nos produtores
        int ini = 0, fim=P-1, happy=0;
        while(ini<=fim){
            int mid=(ini+fim)/2;
            if(p[mid]>x) fim = mid-1;
            else {
                happy = max(happy, mid+1);
                ini = mid+1;
            }
        }

        angry += (P-happy);
        
        ini=0; fim=C-1; happy=0;
        //busca nos consumidores
        while(ini<=fim){
            int mid=(ini+fim)/2;
            if(c[mid]<x) ini = mid+1;
            else {
                happy = max(happy, (C-mid));
                fim = mid-1;
            }
        }
        angry += (C-happy);

        if(angry<ans.second){
            ans = {x, angry};
        }
    }

    return ans;
}

int32_t main()
{_
    int t; cin>>t;

    while(t--){
        cin>>P>>C;
        p.clear(); c.clear(); opt.clear();

        opt.insert(0);

        for(int i=1; i<=P; i++){
            int x; cin>>x;
            p.push_back(x);
            opt.insert(x);
        }

        for(int i=1; i<=C; i++){
            int x; cin>>x;
            c.push_back(x);
            opt.insert(x);
        }

        sort(p.begin(), p.end());
        sort(c.begin(), c.end());

        pair<int,int> ans = solve();
        cout<<ans.first<<" "<<ans.second<<endl;
    }

    return 0;
   
}