// Maximum Subset Sum

#include <bits/stdc++.h> 
using namespace std;

const int INF = 0x3f3f3f3f;

#define endl '\n';
typedef long long ll;

int main() {
    int t, n;
    cin >> t;

    while(t--) {
        cin >> n;
        vector<int> v(n);
        int res = -INF;
        int sum = -INF;

        for(int i = 0; i < n; i++){
            cin >> v[i];
        }

        for(int i = 0; i < n; i++) {
            sum = max(sum + v[i], v[i]); // para o caso de termos número negativo anteriormente
            res = max(res, sum);
        }

        cout << res << endl;
    }

    return 0;
}