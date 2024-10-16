// https://vjudge.net/problem/URAL-1225

#include <bits/stdc++.h> 
using namespace std;

int ways(int n) {
    if (n == 0) return 0;
    if (n == 1) return 2;
    if (n == 2) return 2;
    
    vector<int> b(n+1);
    vector<int> v(n+1);

    b[0] = 0;
    b[1] = 1;
    b[2] = 1;

    v[0] = 0;
    v[1] = 1;
    v[2] = 1;

    for(int i = 3; i <= n; i++) {
        b[i] = v[i-1] + v[i-2];
        v[i] = b[i-1] + b[i-2];
    }

    return b[n] + v[n];
}

int main() {
    int n;
    cin >> n;
    cout << ways(n) << endl;

    return 0;
}