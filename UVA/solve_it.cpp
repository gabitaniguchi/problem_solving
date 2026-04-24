#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define euler 2.71828
#define E 0.0001
int p,q,r,s,t,u;
bool possivel;

double f(double x){
    return p*(pow(euler, -x)) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

double busca(){
    double l=0, r=1, ans;

    if(f(l)*f(r)>0){
        possivel = false;
        return 0;
    }

    while((r-l)>E){
        double mid = (r+l)/2;

        if(abs(f(mid)-0.0)<E) return mid;
        else if(f(mid)*f(r)<0){
            l=mid;
            ans = mid;
        }
        else r=mid;

        ans=mid;
    }
    if(abs(f(ans)-0.0)>E) possivel=false;
    return ans;
}

int32_t main()
{_

    while(cin>>p>>q>>r>>s>>t>>u){
        possivel = true;
        double ans = busca();
        if(possivel) cout<<setprecision(4)<<ans<<endl;
        else cout<<"No solution"<<endl;
    }
}