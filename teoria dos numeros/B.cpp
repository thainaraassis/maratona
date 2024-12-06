//  https://codeforces.com/problemset/problem/1765/M

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


void solve(){
	int n;
	cin >> n;
	int i;
	for(i = 2; i * i <= n; i++)
		if(n % i == 0) break;    // pois i é divisor

	if(i * i > n){
		cout << n-1 << " " << 1 << endl;    // se o único divisor for 1 e ele mesmo 
		return;
	}
	int a = n/i;    // a é o maior divisor, sem ser ele mesmo -> pega n e divide pelo menor divisor, da o maior divisor
	int b = n-a;
	cout << a << " " << b << endl;
}

signed main(){ 
    int t, n;
    cin >> t;
    while(t--){
		solve();
	}
}