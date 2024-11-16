// https://vjudge.net/contest/669902#problem
// Prova

#include <bits/stdc++.h> 
using namespace std;

const int INF = 0x3f3f3f3f;

typedef long long ll;

ll m, n;

void solve(vector<ll> a) {
    sort(a.begin(), a.end(), greater<int>());

    m = m - 2*a[0] - 1; // pega os dois lados do primeiro cara, já que é um circulo
    
    for(int i = 1; i < a.size() - 1; i++) {
        m = m - a[i] - 1;
    }

    m -= 1; // ultima posição possivel
    if(m >= 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
    int t;

    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n >> m;

        vector<ll> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        if(n > m) cout << "NO" << endl;
        else solve(a);
    }

    return 0;

}