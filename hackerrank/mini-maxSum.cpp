#include <bits/stdc++.h>

using namespace std;

void miniMaxSum(vector<int> arr) {
    sort(arr.begin(), arr.end());
    long long minSum = (long long)arr[0] + arr[1] + arr[2] + arr[3];
    long long maxSum = (long long)arr[1] + arr[2] + arr[3] + arr[4];
    
    cout << minSum << " " << maxSum << endl;
}