#include <bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;


int32_t main()
{_
    int T; cin>>T;
    for(int t=1; t<=T; t++){
        int n; cin>>n;
        int at=0;
        int l=1, r=0;
        pair<int,pair<int,int>> maior = {0,{0,0}};
        for(int i=1; i<n; i++){
            int x; cin>>x;

            if(x+at>=0) {
                at+=x;
                r++;
            }
            else{
                at=0;
                l=i+1; r=i;
            }

            if(at>maior.first) maior = {at, {l,r}};
            else if(at==maior.first && (r-l+1)>(maior.second.second - maior.second.first +1))
                maior = {at, {l,r}};
        }

        if(maior.first==0) cout<<"Route "<<t<<" has no nice parts"<<endl;
        else cout<<"The nicest part of route "<<t<<" is between stops "<<maior.second.first<<" and "<<maior.second.second+1<<endl;
        
    }
}
