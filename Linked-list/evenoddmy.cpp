//Arrange elements in a Linked List such that all even numbers are placed after odd numbers
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
node* arrange_LinkedList(node* head)
{
    if(head == NULL || head->next ==NULL) return head;
    //node *even = NULL, *odd = NULL , *etail = NULL ,*otail = NULL;
    node *even = NULL, *odd , *etail = NULL ,*otail;
    while( head!=NULL ){
        if( head->data % 2 == 0){
            if(even == NULL && etail == NULL){
                even = head;
                etail=head;
            }
            etail->next = head;
            etail=head;
            head = head->next;
            etail->next = NULL;
        }
        else{
            if( otail ==NULL  && odd == NULL ){
                otail = head;
                odd = head;
                head = head->next;
                otail->next = NULL;
            }
            else{
                otail->next = head;
                otail=head;
                head = head->next;
                otail->next = NULL;
            }
        }
    }
    //if(otail == NULL) return even;
    //otail->next = even;
    return odd;
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
    node*head=takeinput();
    head=arrange_LinkedList(head);
    print(head);
    return 0;
}
