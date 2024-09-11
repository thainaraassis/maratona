// https://codeforces.com/problemset/problem/26/A

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

#define int long long

//O(sqrt(n))
void find_divisors(int n, set<int>& divisors){
	for(int d=1; d*d<=n; d++){
		if(n%d == 0){
			divisors.insert(d);
			divisors.insert(n/d);
		}
	}
}

//O(sqrt(n))
vector<bool> crivo(int n){
	vector<bool> is_composite(n+1, false);
	for(int i=2; i<=n; i++){
		if(not is_composite[i]){
			//primes.push_back(i);
			for(int j=i*i; j<=n; j+=i)
				is_composite[j] = true;
		}
	}
    return is_composite;
}

signed main(){ 
    int n;
    cin >> n;

    vector<bool> primes = crivo(3000);
    int total = 0;
    
    for(int i = 6; i <= n; i++) {
        int primos = 0;

        set<int> divisors;
        find_divisors(i, divisors);
        divisors.erase(1);

        set<int>::iterator it; // Declaração de um iterator para o set
        for(it=divisors.begin(); it!=divisors.end(); it++) { // Percorre o set inteiro
            if(primes[*it] == false) primos++;
        }

        if(primos == 2) total+=1;

    }
    cout << total << endl;
}