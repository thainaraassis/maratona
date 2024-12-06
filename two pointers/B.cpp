// https://codeforces.com/problemset/problem/1354/B

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
    int t;
	string s;
	cin >> t;

	for(int i = 0; i < t; i++) {
		cin >> s;

        int l = 0, r = -1; // ponteiros esquerdo e direito
        int s1 = 0; 
        int s2 = 0; 
        int s3 = 0; 
        int m = 0;

        while(true) {
             
            if((s1 == 0 || s2 == 0 || s3 == 0) && r+1 < s.size()) { // se tivermos isso o segmentos ainda é invalido
                if(s[r+1] == '1')
                    s1++;
                else if(s[r+1] == '2')
                    s2++;
                else s3++;
                r++;	
            }
            
            else if(0 < s1 && 0 < s2 && 0 < s3) {   // segmento é válido, pois temos todos os doces 
                if(m == 0) m = r-l+1;
                else m = min(m, r-l+1);

                if(s[l] == '1')
                    s1--;
                else if(s[l] == '2')
                    s2--;
                else s3--;
                l++;	

            }
            
            else {
                break;
            }
        }
        cout << m << endl;

	}
}