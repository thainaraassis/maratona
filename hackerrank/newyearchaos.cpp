#include <bits/stdc++.h>

using namespace std;

void minimumBribes(vector<int> q) {
    long long bribe = 0;
    
    for(int i = 0; i < q.size(); i++) {
        if(q[i] - i - 1 > 2) {
            cout << "Too chaotic" << endl;
            return;
        }
        
        for(int j = q[i] - 2; j < i; j++) {
            if(q[j] > q[i]) bribe++;  
        }
    }
    
    cout << bribe << endl;
}
