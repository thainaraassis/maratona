// problema K da subregional brasileira de 2024

#include <bits/stdc++.h> 
using namespace std;

int solve(int n, vector<int> c, int sum) {
    vector<int> resp(n);
    vector<int> alice(n); // alice
    vector<int> bob(n); // bob

    bool memo[101][5001];
    memset(memo, false, sizeof(memo));
    memo[0][0] = true; // a soma 0 é sempre possível sem pegar caramelos
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= sum; j++) {
            if(j == 0) memo[i][j] = true;
            else if(j < c[i-1]) memo[i][j] = memo[i-1][j]; // se a quantidade de caramelos for maior que a soma, não cabe
            else memo[i][j] = memo[i-1][j] || memo[i-1][j - c[i-1]];
        }
    }

    if(memo[n][sum] == false) return -1;

    int j = sum;
    int a = 0, b = 0;

    for(int i = n - 1; i >= 0; i--) {
        if(memo[i][j - c[i]]) {
            alice[a] = c[i];
            a++;
            j -= c[i];
        }
        else {
            bob[b] = c[i];
            b++;
        }
    }

    int sum_a = 0, sum_b = 0;
    a = 0;
    b = 0;

    for(int k = 0; k < n; k++){
        if(sum_a <= sum_b) {
            resp[k] = alice[a];
            sum_a += alice[a];
            a++;
        }
        else {
            resp[k] = bob[b];
            sum_b += bob[b];
            b++;
        }
    }

    cout << resp[0];
    for(int i = 1; i < n; i++) {
        cout << " " << resp[i];
    }
    cout << endl;
    return 0;
}

int main() {
    int n;
    cin >> n;
    vector<int> caramelos(n);
    int sum = 0;

    for(int i = 0; i < n; i++) {
        cin >> caramelos[i];
        sum += caramelos[i];
    }

    if(sum % 2 != 0) return -1;
    sum /= 2;

    if (solve(n, caramelos, sum) == -1) {
        cout << -1 << endl;
    }

    return 0;
}