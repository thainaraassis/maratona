#include <bits/stdc++.h>

using namespace std;

int superDigit(string n, int k) {
    
    if(n.size() == 1) return n[0] - '0';
    
    long long sum = 0;
    
    for(int i = 0; i < n.size(); i++) {
        sum += n[i] - '0';
    }
    
    sum *= k;
    
    string r = to_string(sum);
    return superDigit(r, 1);
}