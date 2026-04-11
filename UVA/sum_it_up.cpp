#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(1e5+10)

int t, n;
vector<int> coin(15);
set<vector<int>> opt;

void sums(int idx, int sum, vector<int> temp){
    if(sum==0) {
        opt.insert(temp);
        return;
    }
    if(idx>n) return;

    for(int i=idx+1; i<=n; i++){
        if(sum - coin[i]<0) break;
        temp.push_back(coin[i]);
        sums(i, sum-coin[i], temp);
        temp.pop_back();
    }
    sums(idx+1, sum, temp);
    return;
}

int comp(int a, int b){
    return a>b;
}

int32_t main()
{_
    while(cin>>t>>n){
        if(t==0 && n==0) return 0;
        for(int i=1;i<=n;i++) cin>>coin[i];
        sort(coin.begin()+1, coin.begin()+n+1, comp);
 
        vector<int> temp;
        sums(0, t, temp);

        stack<vector<int>> ans;
        for(auto v: opt) ans.push(v);
        cout<<"Sums of "<<t<<":"<<endl;
        if(ans.empty()) {
            cout<<"NONE"<<endl;
            continue;
        }
        
        while(!ans.empty()){
            auto v = ans.top();
            ans.pop();

            for(int i=0; i<v.size();i++){
                cout<<v[i];
                if(i!=v.size()-1) cout<<"+";
            }
            cout<<endl;
        }
        temp.clear();
        opt.clear();
    }
   
}
