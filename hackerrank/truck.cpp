#include <bits/stdc++.h>

using namespace std;

int truckTour(vector<vector<int>> petrolpumps) {

    int saldo = 0;
    int ini = 0;
    for(int i = 0; i < petrolpumps.size(); i++) {

        saldo += petrolpumps[i][0] - petrolpumps[i][1];
        if(saldo < 0) {
            ini = i+1;
            saldo = 0;
        }
    }
    return ini;
}