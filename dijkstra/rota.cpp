// WA - https://neps.academy/br/exercise/296

#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

const int INF = 0x3f3f3f3f;
int N, M, C, K;

typedef pair<int, int> Edge;
typedef vector<vector<Edge>> Graph;

int dijkstra(Graph &g, int n, int source, int end, vector<int> &route_cost, int route_start, int route_end) {
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq; 
    vector<int> dist(n, INF);
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &[v, w] : g[u]) {
            int cost = d + w;

            if (u >= route_start && u <= route_end && v >= route_start && v <= route_end) {
                if (v == u + 1) {
                    cost = route_cost[v];
                } else {
                    continue; 
                }
            }
            
            if (cost < dist[v]) {
                dist[v] = cost;
                pq.push({cost, v});
            }
        }
    }

    return dist[end];
}


// a - vertice que ta partindo
// b - vertice que ta chegando
// w - peso da aresta
void add_edge(Graph &g, int a, int b, int w) {
    g[a].push_back({b, w});
    g[b].push_back({a, w});
}

int main() {
    while (true) {
        int N, M, C, K;
        cin >> N >> M >> C >> K;

        if (N == 0 && M == 0 && C == 0 && K == 0) break;

        Graph g = Graph(N, vector<Edge>());
        vector<int> route_cost(C, INF);
        route_cost[0] = 0; 

        for (int i = 0; i < M; ++i) {
            int U, V, P;
            cin >> U >> V >> P;
            add_edge(g, U, V, P);
        }

        for (int i = 0; i < C - 1; ++i) {
            for (auto &[v, w] : g[i]) {
                if (v == i + 1) {
                    route_cost[i + 1] = route_cost[i] + w;
                    break;
                }
            }
        }

        int result = dijkstra(g, N, K, C - 1, route_cost, 0, C - 1);
        cout << result << '\n';
    }

    return 0;
}