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
 
//#define int long long


int lcs_size[3010][3010];
string s, t, lcs;

void recupera(int i, int j) {
    if(i >= s.size() || j >= t.size()) return;
    if(s[i] == t[j]) {
        lcs.push_back(s[i]);
        return(recupera(i+1, j+1));
    }
    else if(lcs_size[i+1][j] >= lcs_size[i][j+1]) return(recupera(i+1,j));
    else return(recupera(i,j+1));

}
 
signed main(){ 
    
    cin >> s >> t;

    vector lcs_size(s.size() + 1, vector<int>(t.size() + 1)); // memo

    for(int i = s.size() - 1; i >= 0; i--) {
        for(int j = t.size() - 1; j >= 0; j--) {
            if(s[i] == t[j]) lcs_size[i][j] = 1 + lcs_size[i+1][j+1];
            else lcs_size[i][j] = max(lcs_size[i+1][j], lcs_size[i][j+1]);
        }
    }
    
    recupera(0,0);

    cout << lcs << endl;
}