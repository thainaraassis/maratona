// Factory Machines

#include <bits/stdc++.h> 
using namespace std;

const int INF = 0x3f3f3f3f;

#define endl '\n';
typedef long long ll;

int n; 
ll t;
vector<ll> times;

bool check(ll mid) {
    ll prod = 0;
    for(int i = 0; i < n; i++) {
        prod += mid/times[i];
        if(prod >= t) return 1;
    }
    return 0; // se mesmo somando usando todas as máquinas eu não consigo fazer os t produtos que eu preciso 
}

ll binary_search( ) {
    ll lo = 1, hi = t * times[0];

    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if(check(mid) == 0) lo = mid + 1;
        else hi = mid;
    }
    return lo; 
}

int main() {
    cin>>n;
    cin>>t;
    times.resize(n);
    for(int i=0; i < n;i++) cin >> times[i];
    sort(times.begin(), times.end());
    cout << binary_search() << endl;
    return 0;
}