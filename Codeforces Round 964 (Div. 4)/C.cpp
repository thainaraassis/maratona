#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, n, s, m, l, r;

    cin >> t;

    for(int i = 0; i < t; i++) {
        cin >> n >> s >> m;

        int prev = 0;
        bool bath = false;

        for(int j = 0; j < n; j++) {
            cin >> l >> r;

            if(l - prev >= s) bath = true;
            prev = r;
        }

        if(m - r >= s) bath = true;
        cout << (bath? "YES" : "NO") << endl;
    }
    return 0;
}