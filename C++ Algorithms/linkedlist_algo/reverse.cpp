#include <iostream>
#include "linkedfunc.cpp"
using namespace std;
//reverse using iterators
node* reverse(node* &head){
    node* prev=NULL;
    node* curr=head;
    node* nex;
    while(curr!=NULL){
        nex = curr->next;
        curr->next=prev;


        prev=curr;
        curr=nex;
    }
    return prev;
}
//REVERSE USING RECURSION

node* reverseByRecursion(node* &head){
    if(head==NULL || head->next==NULL)return head; //base case
    node*newhead= reverseByRecursion(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}

int main(){

    node* head = NULL;
    insertAthead(head,15);
    insertAthead(head,11);
    insertAthead(head,7);
    insertAthead(head,5);
    insertAthead(head,35);
    insertAthead(head,75);
    display(head);
    node* newhead = reverseByRecursion(head);
    display(newhead);

return 0;
}


