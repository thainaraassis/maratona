// WA

#include<bits/stdc++.h>
using namespace std;

int xor_op(int a, int b) {
    return (a && !b) || (!a && b);
}

int main() {
    int t, n, x, y;
    cin >> t;

    for(int i = 0; i < t; i++) {
        cin >> n;
        vector<vector<bool>> points(200100, vector<bool>(2, false));
        
        for(int j = 0; j < n; j++) {
            cin >> x >> y;
            points[x][y] = true;
        }

        int ans = 0;
        for(int j = 0; j < n; j++) {
            // se temos (x,0) e (x,1), só precisamos achar o terceiro, que pode ser qualquer um dos outros pontos
            // pois, se y = 0, temos uma hipotenusa "de pe" e y = 1 uma hipotenusa invertida 
            if(points[j][0] && points[j][1]) ans += n - 2;

            // verifica os pontos (x-1, y^1), (x+1, y^1)
            int xor_y = xor_op(j % 2, 1); 
            if (j - 1 >= 0 && j + 1 < n && points[j - 1][xor_y] && points[j + 1][xor_y]) ans++;
        }

        cout << ans << endl;
    }
    return 0;
}