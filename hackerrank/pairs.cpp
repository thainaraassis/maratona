#include <bits/stdc++.h>

using namespace std;

int pairs(int k, vector<int> arr) {

    set<int> s;
    int n;
    int p = 0;

    for(int i = 0; i < arr.size(); i++) s.insert(arr[i]);

    for(int i = 0; i < arr.size(); i++) {
        n = arr[i] - k; /* numero que precisamos achar no set */
        if(s.find(n) != s.end()) p++;
    }

    return p;
}
