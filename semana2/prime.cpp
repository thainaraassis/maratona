#include <bits/stdc++.h>
using namespace std;

//O(sqrt(n))
bool is_prime(int n){
	if(n == 1) return false;
	bool flg = true;
	for(int i=2; i*i<=n; i++)
		if(n%i == 0) flg = false;
	return flg;
}

signed main(){
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	cout << is_prime(n) << endl; 

	return 0;
}	
