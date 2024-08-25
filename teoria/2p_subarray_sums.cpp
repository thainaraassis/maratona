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

int main(){ 

    // passa por cada elemento somente duas vezes no máximo, por conta dos dois ponteiros
    // assim, tempos uma complexidade O(n)

    int n, m;
    int resp = 0;
    cin >> n >> m;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int soma = 0;
    int l = 0; // ponteiro da esquerda
    for(int r = l; r < n; r++) { // ponteiro da direita sempre implementado por 1
        soma += arr[r];
        while(soma > m) {
            soma -= arr[l];
            l++;
        }

        resp += (soma == m);
    }  

    cout << resp << endl;
    return 0;
}