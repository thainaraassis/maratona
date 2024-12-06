#include<bits/stdc++.h>
using namespace std;

#define N 200150
#define pb push_back

int start[N], fin[N], mp[N];
vector<int> adj[N];

int t = 1;

void dfs(int s) {

    start[s] = t;
    mp[t] = s; t++;

    for(int e : adj[s])
        dfs(e);

    fin[s] = t;
}

int main() {
    
    int i,j,k;
    int n,m,q;
    int u,v;

    cin >> n >> q;

    for(i = 2; i <= n; i++){
        cin >> m;
        adj[m].pb(i);
    }

    memset(start,0,sizeof(start));
    memset(fin,0,sizeof(fin));
    memset(mp,0,sizeof(mp));

    dfs(1);

    while(q--) {
        cin >> u >> k;

        if(fin[u]-start[u]<k)
            cout << -1 << endl;
        else
            cout << mp[start[u]+k-1] << endl;
    }

    return 0;
}