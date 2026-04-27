#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(1e5+10)
int A, B, q;

int a(int n){
    return A + B*(n-1);
}

int Sn(int n){
    return (a(1)+a(n))*n/2;
}

int32_t main()
{_
    cin>>A>>B>>q;
    while(q--){
        int l, t, m;
        cin>>l>>t>>m;

        if(a(l)>t){
            cout<<-1<<endl;
            continue;
        }

        int ini = 1, fim=(int)1e12, ans=0;

        while(ini<=fim){
            int mid=(ini+fim)/2;
            if(a(mid)>t || Sn(mid)-Sn(l-1)>m*t) fim=mid-1;
            else {
                ini=mid+1;
                ans=max(ans, mid);
            }
        }
        cout<<ans<<endl;
    }
}