#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, x, y, k;
    cin >> t;

    for(int i = 0; i < t; i++) {
        cin >> x >> y >> k;
        cout << max((2 * ceil((double)x/k))-1, 2 * ceil((double)y/k)) << endl;
    }
    return 0;
}