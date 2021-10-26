//
// Created by abhi on 04/09/2021.
//

// to append last k nodes in front
#include <iostream>
#include "doublyll.cpp"
using namespace std;

node* reversek(node* &head,int k){
    int l=length(head);
    cout<<l<<endl;
    node* tail=head;
    node* newhead=NULL;
    node* newtail=NULL;
    int d=1;
    while(tail->next!=NULL){
        if(d==(l-k)){
            newtail=tail;
            newhead=tail->next;
        }
        d++;
        tail=tail->next;
    }
    if(newhead !=NULL && newtail!= NULL){
        newtail->next=NULL;
        tail->next=head;
        return newhead;
    } else return head;

}
int main(){
node* Head=NULL;
    insertAtTail(Head,15);
    insertAtTail(Head,16);
    insertAthead(Head,19);
    insertAthead(Head,21);
    insertAthead(Head,14);
    insertAthead(Head,13);
    insertAtTail(Head,24);
    display(Head);
    node* newhead=reversek(Head,5);
    display(newhead);
    return 0;
}
