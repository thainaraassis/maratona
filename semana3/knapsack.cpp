// https://atcoder.jp/contests/dp/tasks/dp_d
 
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
ll memo[110][100010]; // itens vai ate 1e2 e capacidade mochila 1e5
int n, W;
vector<int> w, v; 

ll dp(int item, int cap) {  // item e capacidade
    if(cap < 0) return - LINF;
    if(item == n) return 0;

    if(memo[item][cap] != -1) return memo[item][cap];

    return memo[item][cap] = max(dp(item+1, cap), dp(item+1, cap - w[item]) + v[item]);
}
 
signed main(){ 
    
    // dp
    cin >> n >> W;
    w.resize(n);
    v.resize(n);

    for(int i = 0; i < n; i++)
        cin >> w[i] >> v[i];
    
    memset(memo, -1, sizeof memo);
    cout << dp(0, W) << endl;
   
}