#include <bits/stdc++.h>

using namespace std;

vector<int> countingSort(vector<int> arr) {
    vector<int> c(100, 0);
    
    for(int i = 0; i < arr.size(); i++) {
        c[arr[i]]++;
    }
    
    return c;
}