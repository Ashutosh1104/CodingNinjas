#include <iostream>
#include "node.h"

using namespace std;
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

node* rev_linkedlist_itr(node* head)
{
    node *rHead = NULL;
    while( head != NULL ){
        node *temp= head;		// beak the node out
        head = head->next;     
        
        temp->next = rHead;		// make the broken node into new head
        rHead = temp;        
    }
    
    return rHead;
}


node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}

int main(){
    node* head=takeinput();
    head=rev_linkedlist_itr(head);
    print(head);
    return 0;
}



