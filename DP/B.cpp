// https://vjudge.net/contest/658444#problem/B
// Videogame

#include <bits/stdc++.h> 
using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
    int n;
    cin >> n;
    vector<int> h(n+1);
    for(int i = 1; i <= n; i++) cin >> h[i];

    vector<int> dp(n+1); // marca as distancias minimas de ir de 1 até i;
    dp[1] = 0;
    dp[2] = abs(h[2] - h[1]);

    for(int i = 3; i <= n; i++) {
        dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]), dp[i-2] + abs(h[i] - h[i-2]));
    }

    cout << dp[n] << endl;
}