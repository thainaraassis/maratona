#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

#define ll long long
#define N 100006
#define pb push_back

vector<ll>v[N];
bool  vis[N];
ll cnt=1;

ll dfs(ll n) {
    vis[n]=1;
    for(auto it: v[n]){
        if(!vis[it]){
            cnt++;
            dfs(it);
        }
    }
    return cnt;
}

int main() {
    ll m,n,t,b,c,d,i,j,k,x,y,z,l,q,r;

    cin >> n >> m;

    for (ll i = 0; i < m; i++) {
        cin >> x >> y;
        v[x].pb(y), v[y].pb(x);
    }

    dfs(1);
    if(n==m && n==cnt) cout << "FHTAGN!"<< endl;
    else cout<< "NO" << endl;
    return 0;
}