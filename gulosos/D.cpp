// https://vjudge.net/contest/669902#problem/D
// Incêndio Florestal 

#include <bits/stdc++.h> 
using namespace std;

const int INF = 0x3f3f3f3f;

typedef long long ll;

int main() {
    ll n, m, k;
    cin >> n >> m >> k;

    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<int> d;
    for(int i = 1; i < n; i++) {
        d.push_back(b[i] - b[i-1]);
    }

    sort(d.begin(), d.end());

    int litros = 0;

    for(int i = 0; i < n - k; i++) litros += d[i];
    litros = litros + k;

    cout << litros << endl;
    return 0;
}