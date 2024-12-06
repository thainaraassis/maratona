#include <bits/stdc++.h>

using namespace std;



typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;


void decode_huff(node * root, string s) {
    
    int i = 0;
    while(i < s.size()) {
        node* aux = root;
        
        while(aux->left != NULL && aux->right != NULL) {
            if(s[i] == '0') {
                aux = aux->left;
            } 
            else {
                aux = aux->right;
            }
            i++;
        }
        
        cout << aux->data;
    }
}