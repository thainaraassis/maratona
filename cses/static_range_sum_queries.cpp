#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
	cin >> n >> q;
    int values[n] = {};
    int a, b;
    long long sum[n] = {}; 

    for(int i = 0; i < n; i++){
        cin >> values[i];
        if(i == 0) sum[i] = values[i];
        else sum[i] = sum[i-1] + values[i];
    } 
	for(int i = 0; i < q; i ++) {
        cin >> a >> b;
        if(a != b && a-2 >= 0) cout << sum[b-1] - sum[a-2] << endl;
        else if(a-2 < 0) cout << sum[b-1] << endl;
        else cout << values[a-1] << endl;
    }
	
    return 0;
}
