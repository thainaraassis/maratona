// https://vjudge.net/contest/669902#problem/C
// Laboratório

#include <bits/stdc++.h> 
using namespace std;

const int INF = 0x3f3f3f3f;

typedef long long ll;

int main() {
    ifstream infile("breedflip.in");
    
    int n;
    string x, y;

    infile >> n;
    infile >> x >> y;

    infile.close();

    int inversoes = 0;
    int i = 0;

    while(i < n) {
        
        if(x[i] != y[i]) {
            while(x[i] != y[i]) i++;
            inversoes++;
        }
        else i++;
    }


    ofstream outfile("breedflip.out");;
    outfile << inversoes << endl;
    outfile.close();
    return 0;
}