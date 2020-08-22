#include <iostream>
#include "node.h"
using namespace std;
node* skipMdeleteN(node  *head, int M, int N) {
    if(M==0) return NULL;
    node* temp = head;
    int cM=M, cN= N;
    while( temp != NULL){
        if(cM <= 0 ) cM= M;
        if(cN <= 0 ) cN= N;
        while(cM-- > 1 ){
            cout<<cM<<" "<<temp->data<<endl;
            temp = temp->next;
        }
        node *temp2 = temp;
        while(cN-- && temp2->next != NULL){
            temp2 = temp2->next;
        }
        temp->next = temp2->next;
        temp = temp2->next;
    }
    return head;
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
int main()
{
    node* head=takeinput();
    int m,n;
    cin>>m >> n;
    head= skipMdeleteN(head,m,n);
    print(head);
    return 0;
}
