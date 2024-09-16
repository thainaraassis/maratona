// https://www.spoj.com/problems/HOTELS/
 
#include <bits/stdc++.h> 
using namespace std;  
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
 
#define f first
#define s second
 
#define dbg(x) cout << #x << " = " << x << endl
 
typedef long long ll;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
 
#define int long long
 
signed main(){ 
    int n, m;
    cin >> n >> m;
    int hotel[n+1];

    for(int i = 0; i < n; i++) {
        cin >> hotel[i];
    }

    int l = 0;
    int r = 1;
    int sum = hotel[l];
    int max = 0;

    while(l <= n-1) {
       if(sum > max && sum <= m) max = sum;
       if(sum < m && r <= n-1) {
        sum += hotel[r];
        r++;
       }
       else { // sum >= m
        sum -= hotel[l];
        l++;
       }  
    }

    cout << max << endl;
 
}