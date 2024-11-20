#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

const int INF = 0x3f3f3f3f;
int n, m, q;

typedef pair<int, int> Edge;
typedef vector<vector<Edge>> Graph;

vector<int> dijkstra(Graph &g, vector<int> hosp) {
    priority_queue<Edge> pq;
    for(int amb : hosp)
        pq.push({-0, amb-1});
    vector<int> dist(n, INF);

    while(!pq.empty()) {
        int w = - pq.top().f;
        int u = pq.top().s;
        pq.pop();
        if(dist[u] <= w)
            continue;
        dist[u] = w;
        for(auto [v, n_w]: g[u]){
            if(dist[v] > w + n_w) {
                pq.push({-(w + n_w), v});
            }
        }
    }
    return dist;
}

// a - vertice que ta partindo
// b - vertice que ta chegando
// w - peso da aresta
void add_edge(Graph &g, int a, int b, int w) {
    a--; b--;
    g[a].push_back({b, w});
    g[b].push_back({a, w});
}

void solve() {
    Graph g = Graph(m, vector<Edge>());
    for(int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        add_edge(g, a, b, w);
    }
    vector<int> hosp(q);
    for(int &i : hosp) cin >> i;

    vector<int> dist = dijkstra(g, hosp);

    int ans = -1;
    for(int x : dist)
        ans = max(ans, x);
    cout << ans << endl;

}

int main() {
    while(cin >> n >> m >> q) solve();
}