#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int tabuleiro[n][n];
    int sum_lin[n] = {};
    int sum_col[n] = {};
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> tabuleiro[i][j];
            sum_lin[i] += tabuleiro[i][j];
            sum_col[j] += tabuleiro[i][j];
        }
    }   

    int max = 0;
    int sum = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            sum = sum_lin[i] + sum_col[j] - 2 * tabuleiro[i][j];
            if(sum > max) max = sum;
            sum = 0;
        }
    }  
	
    cout << max << endl;
    return 0;
}
