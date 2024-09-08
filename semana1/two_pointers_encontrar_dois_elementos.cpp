#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/* Encontrar dois elementos
 *
 * Entrada: Sequência com n inteiros e um inteiro k
 * Saída: Dois elementos com soma k, ou 0 caso não existam
 *
 * Exemplo:
 * Entrada:
 * 6 9
 * 6 9 7 2 5 2
 * Saída:
 * 2 7
 */

int main() {
	int n; // quantidade de elementos da sequência
	int k; // soma esperada
	cin >> n >> k;
	int l = 0, r = n-1; // ponteiros esquerdo e direito
	vector<int> vs(n);
	// lê a sequência
	for(int& v : vs)
		cin >> v;
	// ordena a sequência (muito importante)
	sort(vs.begin(), vs.end());
	// loop para a movimentação dos ponteiros
	// para quando r <= l
	while(l < r) {
		int s = vs[l] + vs[r]; // soma dos elementos atuais
		// se a soma atual é maior do que a esperada
		// decrementa o ponteiro esquerdo
		if(k < s) {
			r--;	
		}
		// se a soma atual é menor do que a esperada
		// decrementa o ponteiro esquerdo
		else if(s < k) {
			l++; 
		}
		// senão, a soma é exatamente a esperada, então
		// podemos imprimir os elementos atuais
		else {
			cout << vs[l] << ' ' << vs[r] << '\n';
			return 0;
		}
	}
	// se o loop terminou sem uma resposta, então não existem
	// elementos de soma k
	cout << "0\n";
	return 0; 
}