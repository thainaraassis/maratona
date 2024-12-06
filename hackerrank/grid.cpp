#include <bits/stdc++.h>

using namespace std;

string gridChallenge(vector<string> grid) {
    string a = "YES";
    
    for(int i = 0; i < grid.size(); i++) {
        sort(grid[i].begin(), grid[i].end());
    }
    
    for(int j = 0; j < grid.size(); j++) {
        string aux;
        string s;
    
        for(int i = 0; i < grid.size(); i++) {
            aux.push_back(grid[i][j]);
        }
        
        s = aux;
        sort(s.begin(), s.end());
        
        if(s.compare(aux) != 0) a = "NO";
    }
    
    return a;
}