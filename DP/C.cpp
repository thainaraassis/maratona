// https://vjudge.net/contest/658444#problem/C
// Autocompletar

#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main() {
    string s;
    string t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();

    vector<vector<int>> dist(n + 1, vector<int>(m + 1)); 

    for(int i = 0; i <= n; i++) dist[i][0] = i; // tanto que sobra para remover de s
    for(int j = 0; j <= m; j++) dist[0][j] = j; // tanto que sobra para acrescentar em t
  
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s[i-1] == t[j-1]) dist[i][j] = dist[i-1][j-1]; // se são iguais, não precisa substituir nem nada, então sera igual a distancia da sequencia anterior
            else dist[i][j] = 1 + min(min(dist[i-1][j], dist[i][j-1]), dist[i-1][j-1]); 
            // minimo entre, respectivamente, remover, acrescentar e substituir
        }
    }

    cout << dist[n][m] << endl;
    return 0;
}