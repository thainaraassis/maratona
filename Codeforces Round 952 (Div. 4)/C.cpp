#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, n;

    cin >> t;

    for(int i = 0; i < t; i++) {
        cin >> n;

        vector<int> v(n);
        for(int j = 0; j < n; j++) {
            cin >> v[j];
        }

        set<int> s;
        int sum = 0; 
        int ans = 0;

        for (int j = 0; j < n; j++) {
            sum += v[j];
            s.insert(v[j]);
            if (sum % 2 == 0 && s.find(sum/2) != s.end()) ans++;
        }

        cout << ans << endl;  
    }

    return 0;
}