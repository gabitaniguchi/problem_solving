#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(27)

vector<int> primes;
map<int,int> primo_position;
int fatores[28][9];
string s;

void fatoracao(int x){
    int n = x;
    for(int i=0; i<9; i++){
        int p = primes[i];
        // se x eh primo
        if(p*p > x){
            break;
        }
        if(x%p==0){
            int exp=0;
            while(x%p==0){
                x/=p;
                exp++;
            }
            fatores[n][i] = exp;
        }
    }

    //x eh primo
    if(x>1){
        fatores[n][primo_position[x]] = 1;
    } 
}

void init(){
    primes = {2, 3, 5, 7, 11, 13, 17, 19, 23};

    primo_position[2] = 0;
    primo_position[3] = 1;
    primo_position[5] = 2;
    primo_position[7] = 3;
    primo_position[11] = 4;
    primo_position[13] = 5;
    primo_position[17] = 6;
    primo_position[19] = 7;
    primo_position[23] = 8;

    for(int i=2; i<=27; i++) {
        fatoracao(i);

        for(int k=0;k<9;k++){
            fatores[i][k] += fatores[i-1][k];
        }
    }
}

bool check_res(vector<int>& v){
    for(int i=0; i<9; i++){
        if(v[i]!=0) return false;
    }
    return true;
}

bool achou = false;
void back(string &teste, vector<int> &res, int last_char){
    if(achou) return;
    if(check_res(res)){
        if(teste!=s) {
            cout<<teste<<endl;
            achou=true;
        }
        return;
    }

    bool so_resta_primo_2 = true;
    for (int i = 1; i < 9; i++) {
        if (res[i] > 0) { so_resta_primo_2 = false; break; }
    }

    if (so_resta_primo_2) {
        string tentativa = teste;
        // O que sobrou de res[0] (fatores de 2) viram letras 'a'
        for (int k = 0; k < res[0]; k++) tentativa += 'a';
        
        sort(tentativa.begin(), tentativa.end()); // Garantir menor lexicográfica

        if (tentativa != s) {
            cout<<tentativa<<endl;
            achou = true;
        }
        return;
    }

    for(int i=last_char;i<=27; i++){
        bool negativo=false;
        vector<int> next(9);

        for(int j=0; j<9; j++){
            next[j] = res[j] - fatores[i][j];
            if(next[j]<0) negativo=true;
        }

        if(negativo) continue;
        string teste_nxt  = teste + char(i+'a'-2);
        back(teste_nxt, next, i);
        if(achou) return;
    }
}

int32_t main()
{_
    init();

    int t; cin>>t;
    while(t--){
        cin>>s;
        achou = false;
        vector<int> fatores_iniciais(9);
        for(auto c: s){
            int fat = c-'a'+2;
            for(int i=0; i<9; i++){
                fatores_iniciais[i] += fatores[fat][i];
            }
        }
        for(int i=0; i<9; i++) cout<<fatores_iniciais[i]<<" ";
        string teste = "";
        back(teste, fatores_iniciais, 3);
        if(!achou) cout<<"Impossible"<<endl;
    }


   
}