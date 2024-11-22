// WA - https://vjudge.net/contest/669902#problem/E
// Parênteses  

#include <bits/stdc++.h> 
using namespace std;

const int INF = 0x3f3f3f3f;

typedef long long ll;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int aberto = 0;
    int fechado = 0;
    int consecutivos = 0;

    if(n % 2 != 0 || s[0] == ')' || s[n-1] == '(') cout << ":(" << endl;
    else {
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') aberto++;
            else if(s[i] == ')') fechado++;
        }

        for(int i = 0; i < n; i++) {
            if(s[i] =='?') {
                if(aberto < n/2) {
                    s[i] = '(';
                    aberto++;
                }
                else {
                    s[i] = ')';
                    fechado++;
                }
            }
        }

        aberto = 0;
        fechado = 0;
        for(int i = 1; i < n; i++) {
            if(s[i] == '(') aberto++;
            else if(s[i] == ')') fechado++;
            if(i <= n-1 && aberto == fechado) {
                cout << ":(" << endl;
                return 0;
            }
        }
        cout << s << endl;
        
    }
    
    return 0;
}