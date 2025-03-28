// Subarray Sums II

// kadane O(n)

#include <bits/stdc++.h> 
using namespace std;

const int INF = 0x3f3f3f3f;

#define endl '\n';
typedef long long ll;

int main() {
    int n; cin >> n;
    ll x; cin >> x;

    vector<ll> a(n+1);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<ll> prefixsum;
    map<ll,ll> restos;
    restos[0] = 1;
    ll sum = 0;
    ll subarrays = 0;

    for(int i = 0; i < n;i++){
        sum += a[i];
        prefixsum.push_back(sum);

        subarrays += restos[prefixsum[i] - x];

        restos[sum]++;

    }

    cout << subarrays << endl;

    return 0;
}