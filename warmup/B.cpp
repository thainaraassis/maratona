// Doors and Keys

#include <bits/stdc++.h> 
using namespace std;

const int INF = 0x3f3f3f3f;

#define endl '\n';
typedef long long ll;

int main() {
    int t;
    string mapa;
    bool nao;

    map<char, bool> m;

    cin >> t;
    while(t--) {
        cin >> mapa;

        nao = false;
        m['R'] = false;
        m['G'] = false;
        m['B'] = false;

        for(int i = 0; i < 6; i++) {
            if (mapa[i] == 'r'){
                m['R'] = true;
            }
            else if (mapa[i] == 'g'){
                m['G'] = true;
            }
            else if (mapa[i] == 'b'){
                m['B'] = true;
            }
            else if ((mapa[i] == 'R' && m['R'] == false) ||
                     (mapa[i] == 'G' && m['G'] == false) || 
                     (mapa[i] == 'B' && m['B'] == false)){
                cout << "NO" << endl;
                nao = true;
                break;
            }
        }
        if(!nao)
            cout << "YES" << endl;
    }

    return 0;
}