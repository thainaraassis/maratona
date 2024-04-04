#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int m;
    char l;
    int botas[31][2] ={{0}}; // coluna 0 -> botas esquerdas e coluna 1-> botas direitas
    int corretos = 0;

    for(int i = 0; i < n; i++) {
        cin >> m >> l;
        if(botas[m-30][0] > 0 && l == 'D') {
            corretos++;
            botas[m-30][0] -= 1;
        }
        else if(botas[m-30][1] > 0  && l == 'E') {
            corretos++;
            botas[m-30][1] -= 1;
        }
        else if(l == 'E') botas[m-30][0] += 1;
        else botas[m-30][1] += 1;
    }

    cout << corretos << endl;
	
    return 0;
}
