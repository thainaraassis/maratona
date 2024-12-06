#include <bits/stdc++.h>

using namespace std;

int findMedian(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int mid = arr.size()/2;
    return arr[mid];
}