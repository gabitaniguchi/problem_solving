#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define INF (int)(1e18+10)

int pot2[32], pot3[20];

void init(){
    pot2[0] = pot3[0] = 1;
    for(int i=1; i<32; i++) pot2[i] = pot2[i-1]*2;
    for(int i=1; i<20; i++) pot3[i] = pot3[i-1]*3;
}

int busca(int target, int x){
    int i=0, f=19;
    int ans = INF;
    while(i<=f){
        int m=(i+f)/2;

        int chute = pot3[m]*pot2[x];
        if(chute == target) return chute;
        else if(chute < target) i=m+1;
        else{
            ans = min(ans, chute);
            f=m-1;
        }
    }
    return ans;
}

int solve(int target){
    int ans=INF;
    for(int i=0; i<=31; i++){
        int chute = busca(target, i);
        if(chute>=target) ans = min(ans, chute);
    }
    return ans;
}

int32_t main()
{_
    init();
    int n;
    while(cin>>n && n!=0){
        cout<<solve(n)<<endl;
    }
   
}