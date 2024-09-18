// https://codeforces.com/contest/919/problem/C
 
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
    int n, m, k;
    cin >> n >> m >> k;

    char seat[n][m];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)  cin >> seat[i][j];
    }

    int sum = 0;
    int l = 0, up = 0;
    int ways = 0;

    // first look into the rows
    for(int i = 0; i < n; i++) {

        int j = 0;
        sum = 0;
        l = 0;

        while(j < k) {
            if(seat[i][j] == '.') sum++;
            j++;
        }
        if(sum == k) ways++;
        
        while(j < m) {
            if(seat[i][j] == '.') sum++;
            if(seat[i][l] == '.') sum--;
            j++;
            l++;
            if(sum == k) ways++;
        }
    }

    // second look into the colums
    for(int j = 0; j < m; j++) {

        int i = 0;
        sum = 0;
        up = 0;

        while(i < k) {
            if(seat[i][j] == '.') sum++;
            i++;
        }
        if(sum == k) ways++;
        
        while(i < n) {
            if(seat[i][j] == '.') sum++;
            if(seat[up][j] == '.') sum--;
            i++;
            up++;
            if(sum == k) ways++;
        }
    }

    if (k == 1) {
        cout << ways / 2 << endl;  // Divide by 2 since we double count
    } else {
        cout << ways << endl;
    }
}