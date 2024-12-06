#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s, int l, int r) {
    for(int i = l; i < r; i++) {
        if(s[i] != s[r]) return false;
        r--;
    }
    return true;
}

int palindromeIndex(string s) {

    int n = s.size();

    for(int i = 0; i < n; i++) {
        if(s[i] != s[n - 1 - i]) {
            if(isPalindrome(s, i+1,n-1-i)) return i;
            else if(isPalindrome(s, i, n-1-i-1)) return n-i-1;
            return -1;
        }
    }
    return -1;
}
