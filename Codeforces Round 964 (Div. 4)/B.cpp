#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, a1, a2, b1, b2;

    cin >> t;

    for(int i = 0; i < t; i++) {
        cin >> a1 >> a2 >> b1 >> b2;
        
        int ans=0;
        if ((a1>=b1 && a2>b2)||(a1>b1 && a2>=b2)) ans+=2;
        if ((a1>=b2 && a2>b1)||(a1>b2 && a2>=b1)) ans+=2;

        cout << ans << endl;
    }
    return 0;
}