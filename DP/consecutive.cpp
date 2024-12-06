// https://codeforces.com/contest/977/problem/F

#include <bits/stdc++.h> 
using namespace std;  
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
 
#define f first
#define s second
 
#define dbg(x) cout << #x << " = " << x << endl
 
typedef long long ll;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
 
//#define int long long

signed main(){ 
    
    ios_base::sync_with_stdio(false); // Otimização de entrada e saída
    cin.ios_base::sync_with_stdio(false); // Otimização de I/O
    cin.tie(NULL); // Otimização de I/O
    
    int n;
    cin >> n;

    vector<long long> a(n);
    vector<int> dp(n, 1), parent(n, -1); // DP para armazenar o tamanho da subsequência e parent para reconstrução
    map<long long, int> last_index; // Substituindo unordered_map por map para maior estabilidade

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int max_len = 1, max_idx = 0;

    // Preenchendo a tabela dp e mapeando os índices
    for (int i = 0; i < n; i++) {
        if (last_index.count(a[i] - 1)) { // Se existir um valor a[i]-1 na tabela
            int j = last_index[a[i] - 1]; // Pega o índice desse valor
            dp[i] = dp[j] + 1; // Atualiza dp[i] com base no dp[j]
            parent[i] = j; // Define o pai de i como j
        }
        last_index[a[i]] = i; // Atualiza o último índice de a[i]

        // Atualiza o comprimento máximo e o índice final
        if (dp[i] > max_len) {
            max_len = dp[i];
            max_idx = i;
        }
    }

    // Reconstruir a subsequência
    vector<int> result;
    for (int i = max_idx; i != -1; i = parent[i]) {
        result.push_back(i + 1); // Adiciona o índice (em base 1)
    }
    reverse(result.begin(), result.end()); // Reverter a subsequência

    // Saída
    cout << max_len << endl;
    for (int i : result) cout << i << " ";
    cout << endl;



}