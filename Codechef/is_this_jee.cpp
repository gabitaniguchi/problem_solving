#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define pi 3.14159265359
#define E 0.00000001
double b, c;

double func(double x){
    double ans = x*x + b*x + c;
    ans/=sin(x);
    return ans;
}

// achar o mínimo da função
double busca_ternaria(){
    double l=(1e-9), r=pi/2;
    double ans = -1;

    while((r-l)> E){
        double mid1 = l+(r-l)/3;
        double mid2 = r-(r-l)/3;

        if(func(mid1)==func(mid2)) {
            if(ans==-1) ans = func(mid1);
            min(ans, func(mid1));
            l = mid1;
            r = mid2;
        }

        else if(func(mid1)>func(mid2)){
            l = mid1;
            if(ans==-1) ans = func(mid2);
            ans = min(ans, func(mid2));
        }

        else{
            r = mid2;
            if(ans==-1) ans = func(mid1);
            ans = min(ans, func(mid1));
        }
    }

    return ans;
}

int32_t main()
{_
    int t; cin>>t;
    while(t--){
        cin>>b>>c;

        double ans = busca_ternaria();
        cout<<fixed<<setprecision(10)<<ans<<endl;
    }
   
}