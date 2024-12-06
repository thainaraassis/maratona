#include<iostream>
#include<vector>

using namespace std;

/* Cobertura por intervalos
 *
 * Entrada: n intervalos (l_i,r_i) com 1 <= l_i <= r_i 
 *          e q consultas (p_i)
 * Saída: para cada consulta i, quantos intervalos cobrem o ponto p_i 
 *
 * Exemplo:
 * Entrada:
 * 3 3
 * 2 4
 * 3 5
 * 2 8
 * 1
 * 7
 * 3
 * Saída:
 * 0
 * 1
 * 3
 *
 * Note que o primeiro par de inteiros da entrada corresponde
 * à quantidade de intervalos e à quantidade de consultas
 */ 

int main() {
	int n; // quantidade de intervalos
	int q; // quantidade de consultas
	int r = 0; // maior limite direito dentre todos os intervalos
	int a = 0; // soma atual
	cin >> n >> q;
	vector<pair<int,int>> is(n); // intervalos

	// lê os intervalos e encontra r
	for(pair<int,int>& i : is) {
		cin >> i.first >> i.second;
		if(r < i.second)
			r = i.second;
	}

	vector<int> e(r+2, 0); // vetor de eventos
	vector<int> s(r+2); // vetor de soma acumulada 
	// note que um vetor precisa ter r+2 elementos para
	// que a posição l+1 seja válida
	
	// constroi o vetor de eventos
	for(pair<int,int>& i : is) {
		e[i.first]++;
		e[i.second+1]--;
	}

	// constroi a soma acumulada do vetor de eventos
	for(int i = 0; i <= r+1; i++) {
		a += e[i];
		s[i] = a;
	}

	// responde às consultas
	for(int i = 0; i < q; i++) {
		int p;
		cin >> p;
		// confere se a consulta está dentro dos valores
		// calculados
		if(p < 0 || r < p)
			cout << "0\n";
		else
			cout << s[p] << '\n';
	}

	return 0;
}