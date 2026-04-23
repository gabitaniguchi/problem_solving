#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define INF (int)(1e18+10)

int sum_grupo[] = {0, 45, 9045, 1395495, 189414495, INF };
int a1_grupo[] = {0, 1, 11, 192, 2893, 38894};
int afinal_grupo[] = {0, 9, 189, 2889, 38889};
int dez[] = {1, 10, 100, 1000, 10000, 100000};

int find_grupo(int n){
    if(n>0 && n<=9) return 1;
    else if(n>=10 && n<=99) return 2;
    else if(n>=100 && n<=999) return 3;
    else if(n>=1000 && n<=9999) return 4;
    else return 5;
}

int find_n(int n){
    int grupo = find_grupo(n);
    return n-dez[grupo-1]+1;
}

int an(int grupo, int n){
    return afinal_grupo[grupo-1] + grupo*n;
}

int sum_n(int grupo, int n){
    // PA: Sn = (a1 + an)*n/2
    int sn = ((a1_grupo[grupo] + an(grupo, n))*n)/2;
    return sn;
}

// busca o "subgrupo", retornando o último número
int busca_nfinal(int grupo, int seq){
    int i= dez[grupo-1], f=dez[grupo]-1;
    int ans = INF;
    int comeco_grupo = dez[grupo-1];

    while(i<=f){
        int mid = (i+f)/2;
        int n = mid-comeco_grupo+1;

        if(sum_n(grupo, n)<seq) i=mid+1;
        else {
            f=mid-1;
            ans = min(ans, mid);
        }
    }
    return ans;
}

char qual_digito(int grupo, int seq){
    // acha o último número da subsequência
    int limite = busca_nfinal(grupo, seq);
    int comeco_grupo = dez[grupo-1];

    seq -= sum_n(grupo, limite-comeco_grupo);
    //achar o digito de fato
    if(seq<=9) return seq + '0';

    //busca binaria no número da resposta
    int i=10, f=limite, ans=INF;

    while(i<=f){
        int mid = (i+f)/2;
        if(an(find_grupo(mid), find_n(mid))<seq) i=mid+1;
        else{
            f=mid-1;
            ans = min(ans, mid);
        }
    }

    int last = ans-1;
    int prev_sum = an(find_grupo(last), find_n(last));
    int digit = seq - prev_sum;
    deque<char> s;

    while(ans>0){
        s.push_front((ans%10) + '0');
        ans/=10;
    }
    return s[digit-1];
}

int32_t main() {_

    int t; cin>>t;
    while(t--){
        int x; cin>>x;

        // passo 1 - achar o "grupo"
        int grupo;
        for(int i=0; i<5; i++) {
            if(x>sum_grupo[i] && x<=sum_grupo[i+1]) {
                x -= sum_grupo[i];
                grupo = i+1;
                break;
            }
        }

        char ans = qual_digito(grupo, x);
        cout<<ans<<endl;
    }
    return 0;
}