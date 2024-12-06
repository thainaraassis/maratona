// https://codeforces.com/problemset/problem/676/C

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
    string s;
    cin >> s;

    int l = 0, r = -1; // ponteiros esquerdo e direito
	int a = 0; // contador de 'A's
    int b = 0; // contador de 'B's
	int m = 0; 

    while(true) {
		
		if(a <= k || b <= k)
			m = max(m, r-l+1);
		
		if((a <= k || b <= k) && r+1 < s.size()) {
			if(s[r+1] == 'a')
				a++;
            else
				b++;
			r++;	
		}
		
		else if(k < a && k < b) {
			if(s[l] == 'a')
				a--;
            else
                b--;    
			l++; 
		}
		
		else {
			break;
		}
	}
	cout << m << endl;
}
