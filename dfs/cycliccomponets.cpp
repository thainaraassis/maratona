#include <bits/stdc++.h> 
using namespace std;

#define N 200100
#define pb push_back

using namespace std;

bool vis[N];
vector<int> adj[N];
stack<int> st;

void dfs(int s) {
    vis[s]=1;
    for(int e : adj[s]) {
        if(!vis[e]) dfs(e);
    }
    st.push(s);
}

int main() {

	int i,j,k;
	int n,m;
	int u,v;

	cin >> n >> m;
	for(i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int cnt=0;
    for(i = 1; i <= n; i++) {
        if(!vis[i]) dfs(i);

        k = 1;
        if(st.size() > 2) {
            //check if all the elements have two neighbours
            while(!st.empty()) {
                if(adj[st.top()].size()!=2) {
                    k=0;
                    break;
                }
                st.pop();
            }
            if(k) cnt++;
        }

        while(!st.empty())
            st.pop();
    }

    cout << cnt << endl;

	return 0;
}