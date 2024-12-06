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

int gain[100010][10];
int n;
long long memo[100010][10];
long long points = 0;

signed main(){ 
    cin >> n;
    vector gain(n + 1, vector<int>(3 + 1)); 
    vector memo(n + 1, vector<int>(3 + 1));

    for(int i = 0; i < n; i++) cin >> gain[i][0] >> gain [i][1] >> gain[i][2];
    
    memo[0][0] = gain[0][0];
    memo[0][1] = gain[0][1];
    memo[0][2] = gain[0][2];
    
    // qual atividade escolher no dia i dado que escolhemos a atividade j nesse dia
    for(int i = 1; i < n; i++) {
        memo[i][0] = gain[i][0] + max(memo[i-1][1], memo[i-1][2]);
        memo[i][1] = gain[i][1] + max(memo[i-1][0], memo[i-1][2]);
        memo[i][2] = gain[i][2] + max(memo[i-1][0], memo[i-1][1]);
    }

    cout << max({memo[n-1][0], memo[n-1][1], memo[n-1][2]}) << endl;
}