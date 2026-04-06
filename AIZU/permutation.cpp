#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(1e5+10)

int usei[10], n, idx;
string ans;
vector<string> v;

void permuta(int tam, string s){
    if(tam==n) {
        v.push_back(s);
        if(s==ans) idx = v.size()-1;
        return;
    }

    for(int i=1; i<=n; i++){
        if(usei[i]) continue;
        usei[i] = 1;
        string temp;
        if(tam>0) temp = s+" ";
        temp +=  char(i+'0');
        permuta(tam+1, temp);
        usei[i] = 0;
    }
}

int32_t main()
{_
    cin>>n;
    cin.ignore();
    getline(cin, ans);
    permuta(0, "");

    if(idx>0) cout<<v[idx-1]<<endl;
    cout<<ans<<endl;
    if(idx<v.size()-1) cout<<v[idx+1]<<endl;
   
}