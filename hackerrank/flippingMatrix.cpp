#include <bits/stdc++.h>

using namespace std;

int flippingMatrix(vector<vector<int>> matrix) {
    int sum = 0;
    int n = matrix.size();

    for(int i = 0; i < n / 2; i++) {
    for(int j = 0; j < n / 2; j++) {
    sum += max(matrix[i][j], max(matrix[i][n-1-j], max(matrix[n-1-i]
    [j], matrix[n-1-i][n-1-j]))) ;
    }
    }
    return sum;
}
