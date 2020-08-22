#include "node.h"
using namespace std;

// Using -1   as termination
//add at last end;
node* takeInput(){
    int data;
    cin>>data;
    node *head=nullptr;
    
    while(data!=-1){
        node *newNode=new node(data);   // scope of node n(data) isonly one irteration so it will overirde thus dyanic allocation

        if(head==nullptr) head=newNode;  //link list was empty
        else {
            node *temp=head;
            int i=0;
            while(temp->next!=nullptr){
                temp = temp->next;
            }
            temp->next=newNode;
        }

        cin>>data;
    }
    return head;
}


void printLL(node* head){
    node* curr=head;
    while(curr!=nullptr){
        cout<<curr->data<<endl;
        curr=curr->next;
    }
}
int main(){
    node* head=takeInput();

    printLL(head);
}