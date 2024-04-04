#include <bits/stdc++.h>
using namespace std;

int main(){
    string dna;
    int aux = 0;
    int maior = 0;

    cin >> dna;
    for(int i = 1; i <= dna.size(); i++) {
        if(dna[i-1] == dna[i]) aux++;
        else {
            if(aux > maior) maior = aux; 
            aux = 0;
        }
    }

    cout << maior+1 << endl;

    return 0;
}