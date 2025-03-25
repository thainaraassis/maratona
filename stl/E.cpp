// Digital string maximization

#include <bits/stdc++.h> 
using namespace std;

const int INF = 0x3f3f3f3f;

#define endl '\n';
typedef long long ll;

int main() {
    int t;
    cin >> t;
    string s;
    while(t--) {
        cin >> s;

        for(int i = 0; i < s.size(); i++) {

            int max = s[i] - '0';
            int index = i;

            int n = s.size();
            n = min(n, i+9);

            for(int j = i; j < n; j++) {
                if(s[j] - '0' - (j-i) > max) {
                    max = s[j] - '0' - (j-i);
                    index = j;                   
                }   
            }
            
            for(int k = index; k >= i+1; k--){
                s[k] = s[k-1];
            }
            s[i] = max + '0';                 
        }

        cout << s << endl;
    }

    return 0;
}