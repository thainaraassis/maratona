#include<bits/stdc++.h>
using namespace std;

#define INF 1e9

int main() {
    int t, n, m;

    cin >> t;

    for(int i = 0; i < t; i++) {
        cin >> n >> m;

        vector<vector<char>> city(n, vector<char>(m));
		for(int k = 0; k < n; k++){
			for(int j = 0; j < m; j++){
				cin >> city[k][j];
			}
		}

        int itop = INF;
        int jtop = INF;

        int ibottom = -INF;
        int jbottom = -INF;

        for(int k = 0; k < n; k++){
            for(int j = 0; j < m; j++){
                

                if(city[k][j] == '#'){
                    itop = min(itop, k);
                    jtop = min(jtop, j);

                    ibottom = max(ibottom, k);
                    jbottom = max(jbottom, j);
                }
            }
        }

        cout << ((itop + ibottom) / 2) + 1 << " " << ((jtop + jbottom) / 2) + 1 << endl;  
    }
    return 0;
}