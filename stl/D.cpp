// El Classificador

// multiset (Red-Black Tree)
// operações O(log N)

#include <bits/stdc++.h> 
using namespace std;

const int INF = 0x3f3f3f3f;

#define endl '\n';
typedef long long ll;

int main() {
    int n, q;
    cin >> n >> q;

    multiset<ll> ms;
    ll s;
    for(int i = 0; i < n; i++){
        cin >> s;
        ms.insert(s);
    }

    ll min_size;

    while(q--) {
        cin >> min_size;

        auto it = ms.lower_bound(min_size);

        if (it == ms.end()) {
            cout << -1 << endl;
        } else {
            cout << *it << endl;
            ms.erase(it);
        }
    }

    return 0;
}