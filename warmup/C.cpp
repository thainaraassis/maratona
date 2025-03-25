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
        
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }

        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum += v[j];
                res = max(sum, res);
            }
        }

        cout << res << endl;
    }

    return 0;
}