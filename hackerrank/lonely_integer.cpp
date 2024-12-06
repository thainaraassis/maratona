#include <bits/stdc++.h>

using namespace std;

int lonelyinteger(vector<int> a) {
    vector<int> c(101, 0);
    for(int i = 0; i < a.size(); i++) {
        c[a[i]]++;
    }
    
    for(int i = 0; i < c.size(); i++) {
        if(c[i] == 1) return i;
    }
    
    return -1;
    
}