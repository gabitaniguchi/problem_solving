#include <bits/stdc++.h>
using namespace std;

int n, k;
char m[10][10];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
set<set<pair<int, int>>> visualizados;

// s: células já pintadas de vermelho
// candidatos: células '.' que adjacentes a pelo menos uma célula em 's'
void solve(set<pair<int, int>>& s, set<pair<int, int>> candidatos) {
    if (s.size() == k) {
        visualizados.insert(s);
        return;
    }
    if (candidatos.empty()) return;

    // Para evitar TLE e recursão infinita, processamos os candidatos atuais
    while (!candidatos.empty()) {
        pair<int, int> v = *candidatos.begin();
        candidatos.erase(candidatos.begin());

        // 1. Tenta incluir o candidato 'v' no poliminó
        s.insert(v);
        
        // 2. Cria novos candidatos: os antigos + novos vizinhos de 'v'
        set<pair<int, int>> novos_candidatos = candidatos;
        for (int i = 0; i < 4; i++) {
            int nx = v.first + dx[i], ny = v.second + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && m[nx][ny] == '.' && s.find({nx, ny}) == s.end()) {
                novos_candidatos.insert({nx, ny});
            }
        }
        
        solve(s, novos_candidatos);
        
        // 3. Backtrack: remove 'v' para tentar outras combinações no loop while
        s.erase(v);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> m[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (m[i][j] == '.') {
                set<pair<int, int>> s;
                s.insert({i, j});
                
                set<pair<int, int>> candidatos;
                for (int d = 0; d < 4; d++) {
                    int ni = i + dx[d], nj = j + dy[d];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < n && m[ni][nj] == '.') 
                        candidatos.insert({ni, nj});
                }
                
                solve(s, candidatos);
                
                // IMPORTANTE: Após processar tudo que começa com (i, j), 
                // "fechamos" essa célula para nunca mais começar por ela
                // nem usá-la em outros poliminós, evitando duplicatas.
                m[i][j] = '#'; 
            }
        }
    }

    cout << visualizados.size() << endl;
    return 0;
}