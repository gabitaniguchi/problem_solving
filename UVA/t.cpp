#include <bits/stdc++.h>
using namespace std;

#define int long long

// Quantidade de dígitos de um número n
int contarDigitos(int n) {
    if (n < 10) return 1;
    if (n < 100) return 2;
    if (n < 1000) return 3;
    if (n < 10000) return 4;
    if (n < 100000) return 5;
    return 6;
}

vector<int> comprimentoS; // comprimento de cada bloco S_i (1, 12, 123...)
vector<int> totalS;       // total acumulado (S1 + S2 + S3...)

void precompute() {
    int acumulado = 0;
    int tam_atual_i = 0;
    
    // Até ~45000 é suficiente para cobrir 2^31-1 posições
    for (int i = 1; acumulado <= 2147483647LL; i++) {
        tam_atual_i += contarDigitos(i);
        acumulado += tam_atual_i;
        comprimentoS.push_back(tam_atual_i);
        totalS.push_back(acumulado);
    }
}

void solve() {
    int n;
    cin >> n;

    // 1. Achar em qual bloco Sk a posição n se encontra
    // O primeiro Sk tal que totalS[k] >= n
    auto it = lower_bound(totalS.begin(), totalS.end(), n);
    int idx = distance(totalS.begin(), it);
    
    // n agora é a posição dentro do bloco S_idx
    if (idx > 0) n -= totalS[idx - 1];

    // 2. Achar em qual número dentro de 1, 2, 3...idx o n-ésimo dígito está
    int num = 1;
    while (true) {
        int d = contarDigitos(num);
        if (n <= d) {
            // O dígito está neste número!
            string s = to_string(num);
            cout << s[n - 1] << endl;
            return;
        }
        n -= d;
        num++;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    precompute();
    int t; cin >> t;
    while (t--) solve();
    return 0;
}