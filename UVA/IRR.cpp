#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(1e5+10)

int32_t main()
{_
    int t;
    while(cin>>t && t!=0){
        vector<int> c(t+5);
        for(int i=0;i<=t; i++) cin>>c[i];
        double ini = -0.999999, fim = 1e6;
        for(int i=1;i<=100;i++){
            double mid = (ini+fim)/2;

            double temp = c[0];
            for(int i=1; i<=t; i++) {
                temp += c[i]/pow((1.0+mid), i);
            }

            if(temp > 0) ini = mid;
            else fim = mid;
        }

        cout<<fixed<<setprecision(2)<<fim<<endl;

    }
   
}