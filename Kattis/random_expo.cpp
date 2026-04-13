#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(1e5+10)

deque<int> dig;
bool achou=false;

void random(int idx, int num, vector<int> & ans){
    if(num==0 && idx==dig.size()){
        for(auto x: ans) cout<<x<<" ";
        cout<<endl;
        achou=true;
        return;
    }
    if(idx>=dig.size()) return;

    int pot = 0;
    int base = 1;
    int dez = pow(10, dig.size()-idx-1);
    vector<int> mult;
    mult.push_back(1);
    while(base*dez*dig[idx]<=num){
        base *= dig[idx];
        mult.push_back(base);
        pot++;
    }
    for(int i=pot; i>=0; i--){
        int temp = dez*mult[i];
        if(num-temp<0) continue;
        ans.push_back(i);
        random(idx+1, num - temp, ans);
        if(achou) return;
        ans.pop_back();
    }
}

int32_t main()
{_
    int a, b; cin>>a>>b;
    int mult=10;

    while(a>1){
        dig.push_front(a%10);
        a/=10;
    }

    vector<int> ans;
    random(0, b, ans);
}