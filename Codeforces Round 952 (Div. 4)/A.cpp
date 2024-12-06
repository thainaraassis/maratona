#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    string a, b;

    cin >> t;

    for(int i = 0; i < t; i++) {
        cin >> a >> b;
        swap(a[0], b[0]);
        cout << a << " " << b << endl;
    }

    return 0;
}