#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(1e5+10)

int ax, ay, bx, by, cx, cy, dx, dy;

double busca_ternaria(){
    double ini=0, fim=1;

    for(int i=1; i<=100; i++){
        double mid1 = ini + (fim-ini)/3;
        double mid2 = fim - (fim-ini)/3;

        double x1 = ax + mid1*(bx-ax);
        double y1 = ay + mid1*(by-ay);
        double x2 = cx + mid1*(dx-cx);
        double y2 = cy + mid1*(dy-cy);

        double f1 = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);

        double x3 = ax + mid2*(bx-ax);
        double y3 = ay + mid2*(by-ay);
        double x4 = cx + mid2*(dx-cx);
        double y4 = cy + mid2*(dy-cy);

        double f2 = (x3-x4)*(x3-x4) + (y3-y4)*(y3-y4);

        if(f1>f2) ini = mid1;
        else fim = mid2;
    }

    double x1 = ax + fim*(bx-ax);
    double y1 = ay + fim*(by-ay);
    double x2 = cx + fim*(dx-cx);
    double y2 = cy + fim*(dy-cy);

    double ans = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    return sqrt(ans);
}

int32_t main()
{_
    int t; cin>>t;
    for(int i=1; i<=t;i++){
        cin>>ax>>ay>>bx>>by>>cx>>cy>>dx>>dy;
        double ans = busca_ternaria();
        cout<<"Case "<<i<<": ";
        cout<<fixed<<setprecision(10)<<ans<<endl;
    }
   
}