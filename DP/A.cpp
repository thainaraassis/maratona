// https://vjudge.net/contest/658444#problem/A
// Troco

#include <bits/stdc++.h> 
using namespace std;

const int INF = 0x3f3f3f3f;

// int memo[110][1000010]; // numero de moedas e valor do troco

// int min_troco(int i, int troco) { // sendo i o índice da moeda
//     if(troco == 0) return 0;
//     else if(troco < 0 || i == n) return INF; //não pode pegar de jeito nenhum

//     if(memo[i][troco] != INF) return memo[i][troco];

//     // o minimo entre não pegar a moeda para troco e ter a possibilidade de pegar a mesma moeda
//     else memo[i][troco] = min(min_troco(i+1, troco), 1 + min_troco(i, troco - moedas[i])); 
//     return memo[i][troco];
// }

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> moedas(n);
    for(int i = 0; i < n; i++) {
        cin >> moedas[i];
    }

    vector<int> dp(x+1, INF);
    dp[0] = 0;

    for(int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if(i-moedas[j] >= 0) dp[i] = min(dp[i], dp[i - moedas[j]] + 1);  // pega a moeda ou não
        }
    }

    if(dp[x] == INF) cout << -1 << endl;
    else cout << dp[x] << endl;
    return 0;
}