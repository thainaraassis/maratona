//  https://codeforces.com/problemset/problem/275/C

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
    int n, k;
    cin >> n >> k;

    set<int> conj;
    int a;

    for(int i = 0; i < n; i++) {
        cin >> a;
        conj.insert(a);
    }

    for(auto it : conj)
		conj.erase(k*it);

	cout << conj.size() << endl;   

}