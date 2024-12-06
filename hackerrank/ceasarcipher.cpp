#include <bits/stdc++.h>

using namespace std;

string caesarCipher(string s, int k) {
    string r;
    int c;
    
    k = k % 26;
    
    for(int i = 0; i < s.size(); i++) {
        
        if(s[i] >= 65 && s[i] <= 90) {
            if(s[i] + k <= 'Z') r.push_back(s[i] + k);
            else {
                c = (s[i] + k) - 'Z';
                r.push_back('A' + c - 1);
            }
        }
        else if(s[i] >= 97 && s[i] <= 122) {
            if(s[i] + k <= 'z') r.push_back(s[i] + k);
            else {
                c = (s[i] + k) - 'z';
                r.push_back('a' + c - 1);
            }
        }
        else r.push_back(s[i]);
    }
    return r;
}