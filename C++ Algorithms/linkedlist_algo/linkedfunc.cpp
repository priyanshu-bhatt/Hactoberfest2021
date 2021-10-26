//
// Created by abhi on 03/09/2021.
//

//
// Created by abhi on 03/09/2021.
//
#include<iostream>
using namespace std;
class node{
public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};

void inserAtTail(node* &head,int val){
    node* n = new node(val);
    if(head==NULL){
        head=n;return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
void insertAthead(node* &head,int val){
    node*n = new node(val);
    node* temp=head;
    head=n;
    n->next=temp;
}
void display(node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<endl;
}

void deletehead(node* &head){
    node* temp = head;
    head=head->next;
    delete temp;
}
void deleteval(node* &head,int key){
    if(head==NULL)return;
    if(head->next==NULL){deletehead(head);return;}
    node* temp=head;
    while(temp->next->data!=key){
        if(temp->next==NULL)return;
        temp=temp->next;
    }
    node* todelete = temp->next;
    temp->next=temp->next->next;
    delete todelete;
}


