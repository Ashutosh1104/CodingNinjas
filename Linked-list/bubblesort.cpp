//bubble sort iterative
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
node* bubble_sort_LinkedList_itr(node* head) 
{ 
	node *prev=NULL , *curr=head ;
    
    while( curr != NULL && curr->next != NULL ){
        node* next = curr->next;
        if( curr->data > next->data ){
            cout<<prev->data<<" "<<curr->data<<" "<<next->data<<endl;
            if( prev != NULL ) prev->next = curr->next;
            else if( prev == NULL ) head = next;
            curr->next = next->next;
            next->next = curr;
        }
        if( prev == NULL ) prev = head;
        else prev = curr;
        curr = curr->next;
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
    head=bubble_sort_LinkedList_itr(head);
    print(head);
}
