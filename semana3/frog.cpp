// https://atcoder.jp/contests/dp/tasks/dp_b
 
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

const int MAX = 1e5+10;
int memo[MAX];
int n, k;
vector<int> h; 

int dp(int i) {
    if(i == 0) return 0; // custo é 0 
    if(memo[i] != - 1) return memo[i];

    int ret = INF;
    for(int j = max(0, i-k); j < i; j++) // o max para não pegar valor negativo de indice
        ret = min(ret, dp(j) + abs(h[j] - h[i]));

    return memo[i] = ret;
}
 
signed main(){ 
    
    // dp
    // cin >> n >> k;
    // h.resize(n);
    
    // for(int& i : h) cin >> i;
    // memset(memo, -1, sizeof memo);
    // cout << dp(n-1) << endl;
    

    // bottom-up
    cin >> n >> k;
    vector<int> h(n);
    
    for(int& i : h) cin >> i;

    vector<int> memo(n);

    memo[0] = 0;
    for(int i = 1; i < n; i++) {
        memo[i] = INF;
        for(int j = max(0, i-k); j < i; j++) 
            memo[i] = min(memo[i], memo[j] + abs(h[j] - h[i]));

    }

    cout << memo[n-1] << endl;
}
