#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
vector<int> pot(13), pref(13);

void init(){
    pot[0] = 1; pref[0]=0;
    for(int i=1; i<=12; i++) pot[i] = pot[i-1]*5;
    for(int i=1; i<=12; i++) pref[i] = pref[i-1] + i-1;
}

int traling_zeros(int mid){
    int total = 0;
    for(int i = 1; i <= 12; i++) {
        if(pot[i] > mid) break;
        total += mid / pot[i];
    }
    return total;
}

int32_t main()
{_
    int t; cin>>t;
    init();
    for(int i=1; i<=t; i++){
        int k; cin>>k;

        int ini=5, fim=(1e18);
        int ans=-1;
        while(ini<=fim){
            int mid = (ini+fim)/2;
            if(traling_zeros(mid)>k) fim=mid-1;
            else if(traling_zeros(mid)==k) {
                ans=mid;
                fim = mid-1;
            }
            else ini=mid+1;
        }

        cout<<"Case "<<i<<": ";
        if(ans==-1) cout<<"impossible"<<endl;
        else cout<<ans<<endl;
    }
   
}