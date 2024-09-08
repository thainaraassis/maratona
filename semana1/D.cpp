// https://codeforces.com/problemset/problem/313/B

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
    string s;
    cin >> s;

    int m;
    cin >> m;
    
    vector<int> b(s.size());    // vetor binário, 1 se c_i = c_(i-1), 0 se não 	
    b[0] = 0;
    char c = s[0];

	for(int i = 1; i < s.size(); i++) {
		if(s[i] == c) b[i] = 1;
        else b[i] = 0;    
        c = s[i];   
	}

    vector<int> sum(s.size());
    sum[0] = 0;
    for(int i = 1; i < s.size(); i++) {
		sum[i] = b[i] + sum[i-1];
	}

    
    int start, end;

	for(int i = 0; i < m; i++) {
		cin >> start >> end;
        cout << sum[end-1] - sum[start-1] << endl;
	}

}