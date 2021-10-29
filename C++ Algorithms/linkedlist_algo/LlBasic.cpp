//
// Created by abhi on 02/09/2021.
//
#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
    node(int dat){
        data=dat;
        next=NULL;
    }

};
void inserAtTail(node* &head,int val){
    node* n= new node(val);
    if(head->next ==NULL){
        head=n; return;
    }
        node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
void display(node* head){
    node* temp;
    temp= head;
    while(temp->next!=NULL){
        cout<<temp->data<<"->";
    }
}
int main(){
    node* Head;
    inserAtTail(Head,15);
    inserAtTail(Head,16);
    display(Head);
    return 0;
}