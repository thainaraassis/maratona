#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; 
    cin >> t;

    int n, u;
    int q, index;
    int l, r, val;

    for(int i = 0; i < t; i++) {

        cin >> n >> u;
        int array[n] = {};

        for(int j = 0; j < u; j++) {
            cin >> l >> r >> val;
            array[l] += val;
            array[r + 1] -= val;
        }

        // calcula os valores acumulados
        for (int y = 1; y <= n; y++) {
            array[y] += array[y - 1];
        }

        cin >> q;
        for(int z = 0; z < q; z++) {
            cin >> index;
            cout << array[index] << endl;
        }

    }

    return 0;
}