// https://vjudge.net/contest/669902#problem/B
// Tela

#include <bits/stdc++.h> 
using namespace std;

const int INF = 0x3f3f3f3f;

typedef long long ll;

int main() {
    int k, n;
    cin >> k >> n;

    vector<pair<int, int>> minMax(k);
    int min = 0;
    for(int i = 0; i < k; i++) {
        cin >> minMax[i].first >> minMax[i].second;
        min += minMax[i].first;
    }

    int i = 0;
    int falta = n - min;

    while(i < k && min <= n) {
        int add = minMax[i].second - minMax[i].first;

        if(add >= falta) add = falta;
        minMax[i].first += add;
        falta -= add;

        i++;
    }

    if(falta == 0) {
        cout << "YES" << endl;
        cout << minMax[0].first;
        for(int i = 1; i < k; i++) {
            cout << " " << minMax[i].first;
            cout << endl;
        }
    }

    else cout << "NO" << endl;

    return 0;
}