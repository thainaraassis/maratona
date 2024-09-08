#include<iostream>
#include<string>

using namespace std;

/* Sequência de DNA
 *
 * Entrada: Sequência de DNA composta das bases 'A', 'C', 'G' e 'T' 
 *          e um inteiro k
 * Saída: O tamanho do maior segmento com até k bases 'A'
 *
 * Exemplo:
 * Entrada:
 * TAGAATCA
 * 2
 * Saída:
 * 5
 */

int main() {
	int k; // limite de 'A's em um segmento
	int l = 0, r = -1; // ponteiros esquerdo e direito
	int a = 0; // contador de 'A's
	int m = 0; // tamanho do maior segmento com até k 'A's
	string s;
	cin >> s;
	cin >> k;
	// loop para a movimentação dos ponteiros
	while(true) {
		// se o segmento atual for válido, atualiza m
		if(a <= k && m < r-l+1)
			m = r-l+1;
		// se o segmento atual for válido, e o ponteiro
		// direito não estiver no final da sequência,
		// incrementa o ponteiro direito, atualizando
		// a quantidade de 'A's
		if(a <= k && r+1 < s.size()) {
			if(s[r+1] == 'A')
				a++;
			r++;	
		}
		// senão, se o segmento atual for inválido,
		// incrementa o ponteiro esquerdo, atualizando
		// a quantidade de 'A's
		else if(k < a) {
			if(s[l] == 'A')
				a--;
			l++; 
		}
		// senão, não há nenhum movimento mais a ser
		// feito, e o loop pode ser interrompido
		else {
			break;
		}
	}
	cout << m << '\n';
	return 0; 
}