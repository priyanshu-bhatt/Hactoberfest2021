#include "doublyll.cpp"
#include <iostream>
using namespace std;

int main(){
    node* Head=NULL;
    insertAtTail(Head,15);
    insertAtTail(Head,16);
    insertAthead(Head,19);
    insertAthead(Head,21);
    display(Head);
    deleteAtHead(Head);
    display(Head);
    insertAthead(Head,98);
    display(Head);
    deleteAt(Head,3);
    display(Head);

    return 0;
}