// https://www.spoj.com/problems/EZDIJKST/

#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

const int INF = 0x3f3f3f3f;
int t, v, k;

typedef pair<int, int> Edge;
typedef vector<vector<Edge>> Graph;

vector<int> dijkstra(Graph &g, int source, int n) {
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq; // Min-heap
    vector<int> dist(n, INF);
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &[v, w] : g[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
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
    cin >> t;
    while (t--) {
        int v, k;
        cin >> v >> k;

        Graph g = Graph(v, vector<Edge>());
        for(int i = 0; i < k; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            add_edge(g, a, b, c);
        }
    
        int A, B;

        cin >> A >> B;

            A--; B--; 

            vector<int> dist = dijkstra(g, A, v);

            if (dist[B] == INF) {
                cout << "NO\n";
            } else {
                cout << dist[B] << '\n';
            }
    }

    return 0;
}