#include <bits/stdc++.h>

using namespace std;

int towerBreakers(int n, int m) {
    if(n % 2 == 0 || m == 1) return 2;
    return 1;
}