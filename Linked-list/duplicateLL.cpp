//Eliminate duplicates from a sorted linked list
#include <iostream>
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
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
node* eliminate_duplicate(node* head)
{
    node* temp = head;
    bool unchanged= true;
    
    while(temp->next != NULL){
        if ( temp->data == (temp->next)->data){
            bool unchanged =false;
            node* del = temp;
            del->next = (del->next)->next;
        }  
        else if( unchanged ) temp =  temp->next;
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
int main(){
    node* head=takeinput();
    head=eliminate_duplicate(head);
    print(head);
    return 0;
}