// https://vjudge.net/contest/658444#problem/E
// Estudos

#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> pontos(n + 1, vector<int> (3 + 1));
    for(int i = 0; i < n; i++) {
        cin >> pontos[i][0] >> pontos [i][1] >> pontos[i][2];
    }

    vector memo(n + 1, vector<int>(3 + 1));
    
    memo[0][0] = pontos[0][0];
    memo[0][1] = pontos[0][1];
    memo[0][2] = pontos[0][2];
    
    // a materia que ele vai escolher hoje, dado que ontem estudou uma das outras duas matérias (a que da mais pontos)
    for(int i = 1; i < n; i++) {
        memo[i][0] = pontos[i][0] + max(memo[i-1][1], memo[i-1][2]);
        memo[i][1] = pontos[i][1] + max(memo[i-1][0], memo[i-1][2]);
        memo[i][2] = pontos[i][2] + max(memo[i-1][0], memo[i-1][1]);
    }

    cout << max({memo[n-1][0], memo[n-1][1], memo[n-1][2]}) << endl;
}