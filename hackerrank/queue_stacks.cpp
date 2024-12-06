#include <bits/stdc++.h>

using namespace std;

struct Queue{
    stack<int> s1, s2;
    
    void enqueue(int x) {
        
        /* while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        
        s1.push(x);
        
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        } */
        
        s1.push(x);
    }
    
    int dequeue() {
        
        /* if(s1.empty()) return -1;
        
        int r = s1.top();
        s1.pop();
        return r; */
        
        if(s1.empty() && s2.empty()) return -1;
        
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        int r = s2.top();
        s2.pop();
        return r;
    }
    
    void print() {
        if(s1.empty() && s2.empty()) cout << -1 << endl;
        
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        cout << s2.top() << endl;
    }
    
};