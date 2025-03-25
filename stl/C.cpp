// Balloon Quantum Popping

// priority queue
// inserção (push): O(logN)
// remoção do maior elemento (pop): O(logN)
// acessar o maior elemento (top): O(1)
// construir um heap a partir de um vetor: O(N) 

// ao invés de ordenar usamos uma pq, assim tendo um custo menor 
// e é mais fácil de colocar os inflados de novo

#include <bits/stdc++.h> 
using namespace std;

const int INF = 0x3f3f3f3f;

#define endl '\n';
typedef long long ll;

int main() {
    ll n, s;
    cin >> n >> s;

    priority_queue<ll> pq; // max-heap (maior elemento no topo)
    ll ballon;
    ll total = 0;

    for(int i = 0; i < n; i++) {
        cin >> ballon;
        pq.push(ballon);
        total += ballon;
    }

    if(total <= s) cout << 0 << endl;

    ll b;
    ll inflated;
    ll deflated;
    ll seconds = 0;

    while(!pq.empty() && total > s) {
        b = pq.top();
        inflated = ceil(b/2);
        deflated = b - inflated;

        total -= deflated;
        seconds ++;

        pq.pop();
        pq.push(inflated); // colocar de volta os baloes cheios
        
    }

    cout << seconds << endl;

    return 0;
}