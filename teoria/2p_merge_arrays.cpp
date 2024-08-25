#include <bits/stdc++.h> 
using namespace std;  

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
 
#define f first
#define s second

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ 

    // basicamente o intercala do mergesort
    // intercalar dois arrays e continuar ordenado 

    int n, m;
    cin >> n >> m;
    int a[n+1], b[m+1];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i]; 

    vector<int> resp;
    int i1 = 0, i2 = 0;
    while(i1 < n || i2 < m) {
        if (a[i1] < b[i2]) resp.push_back(a[i1++]);
        else resp.push_back(b[i2++]);
    }

    for(int x: resp) cout << x << ' ';    
    cout << endl;
    return 0;
}