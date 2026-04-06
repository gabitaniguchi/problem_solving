#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
int n, m[12][12];
int mask_c[12], mask_l[12], mask_b[12];

int quad(int i, int j) {
    return (i / n) * n + (j / n);
}

bool pos=false;

bool backtracking(int i, int j){
    if(i==n*n) return true;

    if(m[i][j]!=0) {
        if(j<(n*n-1)) return backtracking(i, j+1);
        else return backtracking(i+1, 0);
    }

    int q = quad(i,j);

    for(int k=1; k<=n*n; k++){
        if((mask_b[q]>>k&1) || (mask_c[j]>>k&1)|| (mask_l[i]>>k&1)) continue;

        m[i][j] = k;
        mask_b[q] |= (1<<k);
        mask_c[j] |= (1<<k);
        mask_l[i] |= (1<<k);

        bool ans;
        if(j<(n*n-1))ans = backtracking(i, j+1);
        else ans = backtracking(i+1, 0);

        if(ans) return true;

        m[i][j] = 0;
        mask_b[q] &= ~(1<<k);
        mask_c[j] &= ~(1<<k);
        mask_l[i] &= ~(1<<k);
    }

    return false;
}

void solve(){
    for(int i=0; i<n*n; i++){
        for(int j=0; j<n*n; j++){
            if(j>0) cout<<" ";
            cout<<m[i][j];
        }
        cout<<endl;
    }
}

int32_t main()
{_
    bool primeiro = false;
    while(cin>>n){

        if(primeiro) cout<<endl;

        memset(mask_c, 0, sizeof(mask_c));
        memset(mask_l, 0, sizeof(mask_l));
        memset(mask_b, 0, sizeof(mask_b));

        if(n==1){
            cin>>m[0][0];
            cout<<1<<endl;
            continue;
        }

        bool invalido = false;

        for(int i=0; i<n*n; i++){
            for(int j=0; j<n*n; j++){
                cin>>m[i][j];
                int q = quad(i,j);
                if(m[i][j]!=0){
                    int x = m[i][j];
                    if ((mask_l[i] >> x & 1) || (mask_c[j] >> x&1) || (mask_b[q] >> x&1)) {
                        invalido = true;
                    }
                    mask_c[j] |= 1<<(m[i][j]);
                    mask_l[i] |= 1<<(m[i][j]);
                    mask_b[q] |= 1<<(m[i][j]);
                }
            }
        }

        bool ans = backtracking(0,0);
        if(!invalido && ans) solve();
        else cout<<"NO SOLUTION"<<endl;
        primeiro = true;
    }

    return 0;

}