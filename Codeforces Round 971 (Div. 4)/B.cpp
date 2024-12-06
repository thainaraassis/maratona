#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    string s;

    cin >> t;

    for(int i = 0; i < t; i++) {
        cin >> n;
        vector<int> r;
        for(int i = n-1; i >= 0; i--) {
            cin >> s;
            for(int j = 0; j < s.size(); j++) {
                if(s[j] == '#') r.push_back(j+1); 
            }
        }
        for(int i = n-1; i >= 0; i--){
            cout << r[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}