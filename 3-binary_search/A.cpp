// Ruler (easy version)

#include <bits/stdc++.h> 
using namespace std;

const int INF = 0x3f3f3f3f;

#define endl '\n';
typedef long long ll;

int t;


bool check(int mid, int x) {
    if (mid == x) return 0;
    else return 1;
}

int binary_search( ) {
    int lo = 2, hi = 999;

    while (lo < hi) {
        int mid = (lo + hi) / 2;
        cout << "? 1 " << mid << endl;
        cout.flush();

        int x;
        cin >> x;
        
        if(check(mid,x) == 0) lo = mid + 1;
        else hi = mid;
    }
    return lo; 
}

int main() {
    cin >> t;

    while(t--){
        int lo = binary_search();
        cout << "! " << lo << endl;
    }

    return 0;
}