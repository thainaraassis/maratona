// Hard Problem

#include <bits/stdc++.h> 
using namespace std;

const int INF = 0x3f3f3f3f;

#define endl '\n';
typedef long long ll;

int main() {
    int t, m, a, b, c;
    cin >> t;

    while(t--) {
        cin >> m >> a >> b >> c;
        int max = 0;
        int r1 = m;
        int r2 = m;

        if(a > m) {
            max += m;
            r1 -= m;
        }
        else {
            max += a;
            r1 -= a;
        } 
        if(b > m) {
            max += m;
            r2 -= m;
        }
        else {
            max += b;
            r2 -= b;
        }
        
        if(r1 + r2 > c) {
            max += c;
        }
        else max += r1+r2;

        cout << max << endl;

    }

    return 0;
}