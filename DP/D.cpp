// https://vjudge.net/contest/658444#problem/D
// Labirinto 


#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
int n;
ll mod = 1e9 + 7;
vector<vector<char>> labirinto;
vector<vector<int>> memo;


int caminhos(int i, int j) {

    if(i < 0 || j < 0) return 0; // não tem mais para onde ir, acabou o labirinto
    if(labirinto[i][j] == '*') return 0; // pois não tem mais como seguir por esse caminho, achou uma armadilha, estão teria que ir pela outra opção 
    if(i == 0 && j == 0) return 1; //chegamos na extrema esquerda (inicio)
    if(memo[i][j] != -1) return memo[i][j];

    else memo[i][j] = ((caminhos(i-1, j) % mod) + (caminhos(i, j-1) % mod)) % mod;
    return memo[i][j];
    // testa ir para cima e esquerda, respectivamente, já que estamos começando da extrema direita
}

int main() {
    
    cin >> n;
    
    labirinto.resize(n, vector<char>(n));
    memo.resize(n, vector<int>(n, -1));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> labirinto[i][j];
        }
    }
    cout << caminhos(n-1, n-1) << endl;

}