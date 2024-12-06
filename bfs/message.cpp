#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e5 + 1;

int N, M, K, a, b;
int p[maxN], dist[maxN];
bool vis[maxN];
vector<int> G[maxN];

bool bfs(int s, int t) {
    queue<int> Q;
    Q.push(s);
    vis[s] = true;

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int v : G[u]) {
            if (!vis[v]) {
                dist[v] = dist[u] + 1;
                vis[v] = true;
                p[v] = u;
                Q.push(v);
            }
        }
    }

    return vis[t]; 
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    if (!bfs(1, N)) {
        printf("IMPOSSIBLE\n");
        return 0;
    }

    int u = N;
    K = dist[N];
    vector<int> ans(K + 1);
    for (int i = K; i >= 0; i--) {
        ans[i] = u;
        u = p[u];
    }

    cout << K + 1 << endl;
    for (int i = 0; i <= K; i++)
        cout << ans[i] << (i == K ? '\n' : ' ');
}