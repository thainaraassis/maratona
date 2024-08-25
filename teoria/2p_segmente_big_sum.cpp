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

    // tamanho do menor subarray com soma pelo menos M

    int n, m;
    int resp = INF;
    cin >> n >> m;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int soma = 0;
    int l = 0; // ponteiro da esquerda
    for(int r = l; r < n; r++) { // ponteiro da direita sempre implementado por 1
        soma += arr[r];
        while(soma - arr[l] >= m) {
            soma -= arr[l];
            l++;
        }

        if(soma >= m) resp = min(resp, r-l+1);
    }  

    cout << (resp == INF ? - 1 : resp) << endl;
    return 0;
}