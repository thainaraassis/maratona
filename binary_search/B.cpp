// Interesting drink

// binary search to do in O(logN) (upper_bound), but its possible to do in O(n)
// sort O(NlogN)

#include <bits/stdc++.h> 
using namespace std;

const int INF = 0x3f3f3f3f;

#define endl '\n';
typedef long long ll;

int n;
vector<int> prices;

bool check(int mid, int x) {
    if (prices[mid] <= x) return 0;
    else return 1;
}

int binary_search(int x) {
    int lo = 0, hi = n;

    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if(check(mid,x) == 0) lo = mid + 1;
        else hi = mid;
    }
    return lo; 
}

int main() {
    cin >> n;
    prices.resize(n);
    for(int i = 0; i < n; i++) cin >> prices[i];
    sort(prices.begin(), prices.end());
    int q; cin >> q;
    ll m;
    while(q--) {
        cin >> m;

        if(m < prices[0]) {
            cout << 0 << endl;
        }
        else{
            int ans = binary_search(m);
            cout << ans << endl;
        }

    }

    return 0;
}