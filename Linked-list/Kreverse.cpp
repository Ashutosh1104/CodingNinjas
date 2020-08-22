//Implement kReverse(int k) i.e. you reverse first k elements then reverse next k elements and so on
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
node* rev_linkedlist_itr(node* head)
{
    node *rHead = NULL;
    while( head != NULL){
        node *temp= head;		// beak the node out
        head = head->next;     
        
        temp->next = rHead;		// make the broken node into new head
        rHead = temp;        
    }
    
    return rHead;
}
node* kReverse(node*head,int n)
{
 	node *temp = head , *chead = head , *nhead = NULL , *rhead = NULL ,*rtail = head;
    int count = 1;
    while(temp != NULL){
        if( count >= n) count = 1;
        chead = temp;
        while( count <= n-1 && temp->next != NULL){
            temp = temp->next;
            count++;
        }
        if(temp->next != NULL) nhead = temp->next;
        else nhead = NULL;
        temp->next=NULL;
        
        node* rev = rev_linkedlist_itr( chead );
        if( chead == head ) rhead = rev;
        rtail->next = rev;
        rtail = chead;
        temp = nhead;
    } 
    return rhead;
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
    int n;
    cin>>n;
    head=kReverse(head,n);
    print(head);
    return 0;
}
