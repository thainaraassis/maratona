#include <bits/stdc++.h>

using namespace std;

int cookies(int k, vector<int> A) {
    
    /* max heap is the normal pq, min heap is the onde with more arguments */  
    int op = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0; i < A.size(); i++) {
        pq.push(A[i]);
    }
    
    while(pq.size() > 1) {
        int f = pq.top();
        pq.pop();
        int s = pq.top();
        pq.pop();
        
        if(f >= k) return op;
        else {
            op++;
            pq.push(f + 2*s);
        }
    }
    
    if(pq.top() >= k) return op;
    return -1;
    
}
