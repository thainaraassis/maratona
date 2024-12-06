#include <bits/stdc++.h>

using namespace std;

string isBalanced(string s) {

    stack<char> pilha;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '{' || s[i] == '[' || s[i] == '(') pilha.push(s[i]);
        else if((!pilha.empty()) && 
                ((pilha.top() == '{' && s[i] == '}') ||
                (pilha.top() == '[' && s[i] == ']') ||
                (pilha.top() == '(' && s[i] == ')'))) pilha.pop();
        else return "NO"; 
    }
    
    if(pilha.empty()) return "YES";
    return "NO"; /* caso seja um numero impar por exemplo,
    pode acabar o tamanho e sobrar 1 abertura */
}