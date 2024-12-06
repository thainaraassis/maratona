#include <bits/stdc++.h>

using namespace std;

bool cmp (pair<int, int> a, pair <int, int> b) {
    return a.second < b.second; // segundo elemento do pair
}
int main() {
    int n; cin >> n;
    vector<pair<int, int>> v; // vetor de pair (intervalos)
    for(int i=0; i<n; i++) {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), cmp);

    int ans = 0;
    // guloso sempre que puder vai escolher, temos que falar quando ele não vai mais
    int fim = -1;
    for(int i=0; i<n; i++) {
        if(v[i].first > fim) {
            fim = v[i].second;
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}