#include "node.h"
using namespace std;

node* insertIthNode(node *head, int i,int data) {
    node *temp=head;
    int index=0;
    
    while(temp!=NULL && index < i-1){
        index++;
        temp = temp->next;
    }
    if(i==0){                           // inserting at 0 th position
        node* newNode = new node(data);
        newNode->next = head;
        head = newNode;
        return head;
    }
    else if (temp!=NULL){
        node* newNode = new node(data);  // we stop 1 before i the ibdex to be added at i
        newNode->next = temp->next;         // make new code connected to its next node
        temp->next = newNode;            // connect new node at its desired position
    }
    return head;
}

node* deleteIthNode(node *head, int i) {
    node *temp=head;
    int index=0;
    while(temp!=NULL && index < i-1){
        index++;
        temp = temp->next;
    }
    if(i==0){
        head = head->next;
        return head;
    }
    if (temp!=NULL){
        node* del = temp->next;  // we stop 1 before the ibdex to be deleted
        temp->next = del->next;  //bascially skipping del in the links
    }
    return head;
}

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
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
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

    int index,data;
    cout<<"Insert data: ";
    cin>>index>>data;
    head = insertIthNode(head , index , data);         // calling insert function //+1 as its 0 indexed
    printLL(head);

    cout<<"Delete data: ";
    cin>>index;
    head = deleteIthNode(head , index );
    printLL(head);
}