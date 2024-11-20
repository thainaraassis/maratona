// https://codeforces.com/group/xR6OpxQBMc/contest/215144/problem/F

#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
const int INF = 0x3f3f3f3f;
int n, m, x;
 
typedef pair<int, int> Edge;
typedef vector<vector<Edge>> Graph;
 
vector<int> dijkstra(Graph &g, int source) {
    priority_queue<Edge> pq;
    pq.push({-0, source});
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
 
int main() {
    cin >> n >> m >> x;
    Graph g = Graph(n, vector<Edge>());
    for(int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        add_edge(g, a, b, w);
    }
    vector<int> friends(x);
    for(int &i : friends) cin >> i;
 
    vector<int> dist_to_friends = dijkstra(g, 0);
    vector<int> dist_to_icecream = dijkstra(g, n-1);
 
    int ans = INF;
    for(int fr : friends) {
        int w = dist_to_friends[fr-1] + dist_to_icecream[fr-1];
        ans = min(ans, w);
    }
 
    cout << ans << endl;
}