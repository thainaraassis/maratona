// https://codeforces.com/problemset/problem/633/B

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

#define int long long

signed main(){ 
    int m;
    cin >> m;

	int k = 0;
	int nz = 0;

	while (nz < m){
		nz = 0;
		k+=5;       // vai pegando 5!, 10!, 15! ... e vendo quantas vezes o 5 cabe nesses fatoriais, qnt de 0
		int i5 = 5; // os zeros finais em fatoriais são relacionados aos múltiplos de 5 (multiplicação de fatores de 2 e 5, mas os fatores de 5 são menos frequentes).

		while (k/i5 >= 1){  // calcular quantos múltiplos de 5, 25, 125, etc., existem em k!
		    nz += k/i5;
		    i5=5*i5;
		}
	}
	if(nz == m)
		printf("5\n%lld %lld %lld %lld %lld\n", k, k+1, k+2, k+3, k+4);
	else
		cout << 0 << endl;



}