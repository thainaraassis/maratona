// Normal Problem

#include <bits/stdc++.h> 
using namespace std;

const int INF = 0x3f3f3f3f;

#define endl '\n';
typedef long long ll;

// push(x): O(1)
// pop():   O(1)
// top():   O(1)
// size():  O(1)
// empty(): O(1)

// o uso de memória é O(n)

int main() {
    int t;
    cin >> t;

    string a;
    while(t--) {
        cin >> a;

        stack<char> b;

        for(int i = 0; i < a.size(); i++) {
            if(a[i] == 'w') b.push('w');
            else if(a[i] == 'p') b.push('q');
            else if(a[i] == 'q') b.push('p');
        }

        while(!b.empty()) {
            cout << b.top();
            b.pop();
        }

        cout << endl;
    }
    return 0;
}