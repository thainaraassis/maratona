#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
    int n; cin >> n;

    vector<int> v;
    for(int i=0; i<n;i++) {
        int a; cin >> a; v.push_back(a);
    }

    int ans = -INF, soma_ant = -INF;
    for(int i=0; i<n;i++) {
        if(soma_ant < 0) 
            soma_ant = v[i];
        else 
            soma_ant += v[i];
        ans = max(soma_ant, ans);
    }
    return 0;
}