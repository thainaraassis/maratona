// Ruler (hard version)

#include <bits/stdc++.h> 
using namespace std;

const int INF = 0x3f3f3f3f;

#define endl '\n';
typedef long long ll;

int t;


bool check(int mid, int x) {
    if (mid == x) return 1;
    else return 0;
}

int ternary_search() {
    int lo = 2, hi = 999;

    while (lo < hi) {
        int m1 = lo + (hi - lo) / 3;
        int m2 = hi - (hi - lo) / 3;

        cout << "? " << m1 << " " << m2 << endl;
        cout.flush();

        int x;
        cin >> x;

        if (check(m1*m2,x) == 1) lo = m2 + 1;
        else if (check(m1*(m2+1),x) == 1) {
            lo = m1 + 1;
            hi = m2;
        }
        else if(check((m1+1)*(m2+1),x) == 1) hi = m1;
    }

    return lo;
}

int main() {
    cin >> t;

    while(t--){
        int hi = ternary_search();
        cout << "! " << hi << endl;
    }

    return 0;
}