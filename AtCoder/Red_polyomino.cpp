#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  

char m[10][10];
int n, k;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

set<set<pair<int,int>>> ans;

void red(set<pair<int,int>> &s, set<pair<int,int>> & alcancaveis){
    if(s.size()==k) {
        ans.insert(s);
        return;
    }

    if(alcancaveis.empty()) return;

    while (!alcancaveis.empty()) {
        auto[x,y] = *alcancaveis.begin();
        alcancaveis.erase(alcancaveis.begin());

        s.insert({x,y});
        
        set<pair<int, int>> new_alcancaveis = alcancaveis;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && m[nx][ny] == '.' && s.find({nx, ny}) == s.end()) {
                new_alcancaveis.insert({nx, ny});
            }
        }
        
        red(s, new_alcancaveis);

        s.erase({x,y});
    }
}

int32_t main()
{_
    cin>>n>>k;

    for(int i=1;i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>m[i][j];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(m[i][j]=='.') {
                set<pair<int, int>> s;
                s.insert({i, j});
                
                set<pair<int, int>> alcancaveis;
                for (int d = 0; d < 4; d++) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    if (ni >= 1 && ni <= n && nj >= 1 && nj <= n && m[ni][nj] == '.') 
                        alcancaveis.insert({ni, nj});
                }
                
                red(s, alcancaveis);
                
            }
        }
    }

    cout<<ans.size()<<endl;
}