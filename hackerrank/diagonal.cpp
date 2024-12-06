#include <bits/stdc++.h>

using namespace std;

int diagonalDifference(vector<vector<int>> arr) {
    int lrd = 0;
    int rld = 0;
    for(int i = 0; i < arr.size(); i++) {
        lrd += arr[i][i];
    }
    
    for(int i = 0; i < arr.size(); i++) {
        rld += arr[i][arr.size() - 1 - i];
    }
    
    return abs(lrd - rld);
    
}