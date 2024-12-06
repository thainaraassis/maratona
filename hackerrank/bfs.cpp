#include <bits/stdc++.h>

using namespace std;

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {

    vector<int> adj(n+1); /* lista adjacente para representar nosso graph */
    for(int i = 0; i < m; i++) {
        int a = edges[i][0];
        int b = edges[i][1];
        //adj[a].push_back(b);
        //adj[b].push_back(a);
    }

    vector<bool> visited(n+1, false);
    vector<int> dist(n+1, -1);

    queue<int> q;
    visited[s] = true;
    q.push(s);

    while(!q.empty()) {
        int curr = q.front();
        //for(adj[curr])
    }

}