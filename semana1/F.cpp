// https://codeforces.com/problemset/problem/276/C
 
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
    int n, q;
    cin >> n >> q;
 
    int r = 0;
    int a = 0;
 
    vector<int> forca(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> forca[i];
    }
 
    vector<pair<int,int>> in(q); // intervalos
	for(int i = 0; i < q; i++) {
		cin >> in[i].first >> in[i].second;
	}
 
	vector<int> e(n+2, 0); 
	vector<int> sum(n+1, 0); 
	
	// constroi o vetor de eventos  
	for(pair<int,int>& i : in) {
		e[i.first]++;
		e[i.second+1]--;
	}
 
	for(int i = 1; i <= n; i++) {
		a += e[i];
		sum[i] = a;
	}
 
    sort(forca.begin() + 1, forca.end());
    sort(sum.begin() + 1, sum.end());
 
    int maxForca = 0;
    for (int i = 1; i <= n; i++) {
        maxForca += forca[i] * sum[i];
    }
 
    cout << maxForca << endl;
 
}