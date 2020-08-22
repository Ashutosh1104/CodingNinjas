#include "node.h"
using namespace std;

void printLL(node* head){
    node* curr=head;
    while(curr!=nullptr){
        cout<<curr->data<<endl;
        head=curr->next;
    }
}
int main(){
    node n1(5);
    node* head=&n1;
    
    node n2(10);
    n1.next=&n2;
    
    node n3(13);
    n2.next=&n3;

    node n4(17);
    n3.next=&n4;

    node n5(20);
    n4.next=&n5;

    printLL(head);
}