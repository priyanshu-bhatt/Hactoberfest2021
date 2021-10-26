//
// Created by abhi on 03/09/2021.
//
#include<iostream>
#include "linkedfunc.cpp"
node* reversek(node* &head,int k){
    node* currptr=head;
    node* prev = NULL;
    node* nextptr;
    int count =0;
    while(currptr!=NULL && count<k){
        nextptr=currptr->next;
        currptr->next=prev;

        prev=currptr;
        currptr=nextptr;
        count++;
    }
    if(nextptr!=NULL) {
        head->next = reversek(nextptr, k);
    }
    return prev;

}


int main(){
    node* head = NULL;
    int k=2;
    insertAthead(head,15);
    insertAthead(head,11);
    insertAthead(head,7);
    insertAthead(head,5);
    insertAthead(head,35);
    insertAthead(head,75);
    display(head);
    node* newhead= reversek(head,k);
    display(newhead);

    return 0;
}
