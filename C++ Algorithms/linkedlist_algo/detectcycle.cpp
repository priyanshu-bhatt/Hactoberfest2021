//
// Created by abhi on 03/09/2021.
//

/*Floyd's algorithm
 * hare and tortoise algorithm
 *
 *
*/
#include<iostream>
#include "linkedfunc.cpp"
void makeCycle(node * &head,int pos){
    node* temp =head;
    node* sttartpoint;
    int count=1;
    while(temp->next!=NULL){
        if(count==pos){
            sttartpoint= temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=sttartpoint;
}
bool checkCycle(node* head){
    node* hare=head;
    node* tortoise=head;
    while(tortoise!=NULL && tortoise->next!=NULL){
        hare=hare->next;
        tortoise=tortoise->next->next;
        if (tortoise==hare){
            return true;
        }

    }
    return false;
}

void removeCycle(node* &head){
    node* slow=head;
    node* fast= head;
    do {
        slow=slow->next;
        fast=fast->next->next;
    } while (slow!=fast);
    fast=head;
    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
}
int main(){
    node* head = NULL;
    insertAthead(head,15);
    insertAthead(head,11);
    insertAthead(head,7);
    insertAthead(head,5);
    insertAthead(head,35);
    display(head);
    cout<<checkCycle(head)<<endl;
    makeCycle(head,3);
    cout<<checkCycle(head)<<endl;
    removeCycle(head);
    display(head);
    cout<<"HEllo World";


    return 0;
}

