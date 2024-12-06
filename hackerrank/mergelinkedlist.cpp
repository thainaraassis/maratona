#include <bits/stdc++.h>

using namespace std;

typedef struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    
    SinglyLinkedListNode* result = new SinglyLinkedListNode();
    SinglyLinkedListNode* aux = result;
    
    while(head1 != NULL && head2 != NULL) {
        
        if(head1->data <= head2->data) {
            aux->next = head1;
            aux = aux->next;
            head1 = head1->next;
        }
        
        else if(head1->data > head2->data) {
            aux->next = head2;
            aux = aux->next;
            head2 = head2->next;
        }
    }
    
    if (head1 != NULL) {
        aux->next = head1;
    }
    
    if (head2 != NULL) {
        aux->next = head2;
    }
    
    return result->next;
    
}