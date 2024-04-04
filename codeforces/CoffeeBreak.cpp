#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, m;
    cin >> n >> m;
    int mesa[n][m];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cin >> mesa[i][j];
    }

    int max = 0;
    int aux = 0;
    // // verificar o máximo que pode ser pego em coluna
    // for(int j = 0; j < m; j++) {
    //     for(int i = 0; i < n; i++) {
    //         if(mesa[i][j] == 1) aux += 1;
    //         if(aux > max) max = aux;
    //         aux = 0;
    //     }
    // }

    // // verificar o máximo que pode ser pego em linha
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         if(mesa[i][j] == 1) aux += 1;
    //         if(aux > max) max = aux;
    //         aux = 0;
    //     }
    // }

    bool nao_tem_bol = false;

    // verificar o máximo em "quadrados", em "submatrizes"
    // vai percorrer todas combinações de colunas e linhas possíveis dentro de uma matriz mxn
    for(int l_ini = 0; l_ini < n; l_ini++) {
        for(int l_fim = 0; l_fim < n; l_fim++) {

            for(int c_ini = 0; c_ini < m; c_ini++) {
                for(int c_fim = 0; c_fim < m; c_fim++) {
                    
                    // vai verificar a submatriz adquirida
                    for (int i = l_ini; i <= l_fim; i++) {
                        for (int j = c_ini; j <= c_fim; j++) {
                                // se achar algum 0 na submatriz, já não é válido mais
                                if(mesa[i][j] == 0) {
                                    aux = 0;
                                    nao_tem_bol = true;
                                    break;
                                }
                                else aux +=1;
                                
                        }
                        if(nao_tem_bol) break;
                    }
                    if(aux > max) max = aux;
                    aux = 0;
                    nao_tem_bol = false;
                    ///////////////////////////////////////

                }
            }
                
        }
    }

    cout << max << endl;
    
    return 0;
}