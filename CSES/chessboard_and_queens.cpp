#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(1e5+10)
int n, ans=0, row[10], col[10], diag[20], antidiag[20];
char m[10][10];

void chess(int r, int c, int q){
    if(q==8) {
        ans++;
        return;
    }

    if(r>8) return;

    if(m[r][c]!='*' && row[r]==0 && col[c]==0 && diag[c+r-1]==0 && antidiag[c+8-r]==0) {     
        // coloca a rainha
        row[r] = 1;
        col[c] = 1;
        diag[r+c-1] = 1;
        antidiag[c+8-r] = 1;
        chess(r+1, 1, q+1);
        // backtracking
        row[r] = 0;
        col[c] = 0;
        diag[r+c-1] = 0;
        antidiag[c+8-r] = 0;
    }
    
    if(c==8) chess(r+1, 1, q);
    else chess(r, c+1, q);
}

int32_t main()
{_
    for(int i=1; i<=8; i++){
        for(int j=1; j<=8; j++){
            cin>>m[i][j];
        }
    }

    chess(1,1, 0);
    cout<<ans<<endl;
}