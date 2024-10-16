// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

#include <bits/stdc++.h> 
using namespace std;

#define INF 0x3F3F3F3F


int minCost(int n, vector<int>& cuts) {
        
    int k = cuts.size(); 

    int c[k+2][k+2];
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());

    for(int i=0;  i <= k+1; i++) {
        for(int j = 0; j <= k+1; j++) {
            if(j == i+1) c[i][j] = 0;
            else c[i][j] = INF;
        }
    }

    for (int len = 2; len <= k + 1; len++) {  
        for (int i = 0; i + len <= k + 1; i++) {  
            int j = i + len;
            for (int a = i + 1; a < j; a++) {
                if(c[i][j] > c[i][a] + c[a][j] + cuts[j] - cuts[i])
                    c[i][j] = c[i][a] + c[a][j] + cuts[j] - cuts[i];
            }
        }
    }
    return c[0][k+1];
}
