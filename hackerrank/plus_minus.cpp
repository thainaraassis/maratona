#include <bits/stdc++.h>

using namespace std;

void plusMinus(vector<int> arr) {
    double zero = 0;
    double pos = 0;
    double neg =0;
    
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == 0) zero++;
        else if(arr[i] > 0) pos++;
        else neg++;
    }
    cout << fixed << setprecision(6);
    cout << pos/arr.size() << endl;
    cout << neg/arr.size() << endl;
    cout << zero/arr.size() << endl;
}