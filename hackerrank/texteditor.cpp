#include <bits/stdc++.h>

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int q, t, k;
    string s = "", w;
    stack<string> oprS;
    
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> t;
        
        if(t == 1) {
            cin >> w;
            oprS.push(s);
            s.append(w);
        }
        else if(t == 2) {
            cin >> k;
            oprS.push(s);
            s.erase(s.size() - k);
        }
        else if(t == 3) {
            cin >> k;
            cout << s[k-1] << endl;
        }
        else {
            s = oprS.top();
            oprS.pop();
        }
    }
    return 0;
}