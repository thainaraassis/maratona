#include <bits/stdc++.h>
using namespace std;

int main(){

    int matriz[5][5];
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> matriz[i][j];
            if(matriz[i][j] == 1) cout << abs(i - 2) + abs(j - 2) << endl;
        }
    }
    
    return 0;
}