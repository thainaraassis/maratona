#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    string s, p;

    cin >> t;

    for(int i = 0; i < t; i++) {
        cin >> s >> p;

        int n = s.size(), m = p.size();
        int k = 0, j = 0;
        while (k < n) {
            if (j == m) {
                if (s[k] == '?') s[k] = 'a';
                k++;
                continue;
            }
            if (s[k] == '?' || s[k] == p[j]) {
                s[k] = p[j];
                j++;
            }
            k++;
        }

        if (j == m) {
            cout << "YES" << endl;

            for(int k = 0; k < n; k++) {
                cout << s[k];
            }
            cout << '\n';
        }

        else cout << "NO" << endl;
    }

    return 0;
}