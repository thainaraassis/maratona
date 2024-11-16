// https://vjudge.net/contest/669902#problem/F
// Conquistadores de Reinos 

#include <bits/stdc++.h> 
using namespace std;

const int INF = 0x3f3f3f3f;

typedef long long ll;

const int MAXN = 20005;
vector<int> grafo[MAXN];

int dfs(int i, int pai, int cor_atual, vector<int> c) {
    int ans = 0;
    if(c[i] != cor_atual) ans++;
    for(int v: grafo[i]) {
        if(v != pai) ans += dfs(v, i, c[i], c);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> c(n+1);
    int p;

    for(int i = 2; i <= n; i++) {
        cin >> p;
        int a = p; int b = i;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    // dfs para passar pela árvore de cima para baixo
    cout << dfs(1, -1, 0, c) << endl; // cor atual 0 porque ninguém tem ela
    return 0;
    
}