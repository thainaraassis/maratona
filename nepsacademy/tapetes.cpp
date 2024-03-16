#include <bits/stdc++.h>
using namespace std;

int main(){
    long long l, n;
	cin >> l >> n;

	long long lado = l - n + 1; // começa pelo tapete de maior lado/ área
	long long compr = lado;
	long long area = lado*lado;
	
	area += n - 1;
	compr += n - 1;
	
	cout << area << endl;
    return 0;
}