// Rectangles

#include <bits/stdc++.h> 
using namespace std;

const int INF = 0x3f3f3f3f;

#define endl '\n';
//#define int long long
typedef long long ll;

int main() {

    vector<ll> exp;
    exp.push_back(1);
    ll pot = 1;
    for(int i = 1; i < 51; i++) {
        pot *= 2;
        exp.push_back(pot);
    }

    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m, 0)); 

    ll total = 0; // todos subsets com uma celula 

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    // contabilizando as possibilidade das linhas
    for(int i = 0; i < n; i++) {
        int white = 0;
        for(int j = 0; j < m; j++) {
            white += v[i][j];
        }
        int black = m - white;
        // contando os subconjuntos de um conjunto e retirando o conjunto vazio
        total += exp[white] - 1;
        total += exp[black] - 1;
    }

    // contabilizando as possibilidade das colunas
    for(int j = 0; j < m; j++) {
        int white = 0;
        for(int i = 0; i < n; i++) {
            white += v[i][j];
        }
        int black = n - white;
        // contando os subconjuntos de um conjunto e retirando o conjunto vazio
        total += exp[white] - 1;
        total += exp[black] - 1;
    }
  
    // já que contabilizamos cada celula unitaria 2 vezes, 
    // uma durante a passagem das linhas e outra durante a passagem das colunas
    total -= n*m; 

    cout << total << endl;
    return 0;
}