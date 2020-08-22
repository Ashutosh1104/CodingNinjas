#include "node.h"
using namespace std;

// Using -1   as termination
//add at last end;
node* takeInput(){
    int data;
    cin>>data;
    node *head=nullptr;
    node * tail=nullptr;

    while(data!=-1){
        node *newNode=new node(data);   // scope of node n(data) isonly one irteration so it will overirde thus dyanic allocation

        if(head==nullptr) { //link list was empty
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode; 
            tail=newNode;
            //tail= tail->next;
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

int length(node *head) {
    node* temp=head;
    int l=0;
    
    while(temp != nullptr){
        l++;
        temp = temp->next;
    }
    
    return l;
}
int main(){
    node* head=takeInput();

    printLL(head);

    cout<<"lenght is: "<<length(head)<<endl;
}