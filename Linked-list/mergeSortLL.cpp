//merge sort recursive
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
node* mergeTwoLLs(node *head1, node *head2) {
    node *fhead=NULL , *ftail=NULL;
    while(head1 != NULL && head2 != NULL){
        if( head1->data <= head2->data ){
            if( ftail == NULL && fhead == NULL) fhead = head1;
            else ftail->next = head1;
            ftail = head1;
            head1 = head1->next;
        }
        else{
            if( ftail == NULL && fhead == NULL) fhead = head2;
            else ftail->next = head2;
            ftail = head2;
            head2 = head2->next;
        }
    }
    if( head1 == NULL ) ftail->next = head2;
    else if ( head2 == NULL ) ftail->next = head1;
    return fhead;
}
node* midnode(node *head )
{
	node *slow=head, *fast=head;
    while(fast->next != NULL){
        if( fast->next->next == NULL) break;
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
node* mergeSort(node *head) {
    if( head->next == NULL ) return head;
	node* mid = midnode( head );
    node* midAhead = mid->next;
    mid->next=NULL;
    node* left = mergeSort( head );
    node* right = mergeSort( midAhead );
    node* fhead = mergeTwoLLs( left , right );
    return fhead;
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

int main()
{
    node* head=takeinput();
    head= mergeSort(head);
    print(head);
    return 0;
}

