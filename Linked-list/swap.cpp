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

node* swap_help(node *head_ref,int x,int y)
{
	node *prevX = NULL, *currX = head_ref;  
	while (currX && currX->data != x)  
	{  
    	prevX = currX;  
    	currX = currX->next;  
	}  
  	node *prevY = NULL, *currY = head_ref;  
	while (currY && currY->data != y)  
	{  
    	prevY = currY;  
    	currY = currY->next;  
	}  
  
	if (currX == NULL || currY == NULL)  return head_ref;  
  
	if (prevX != NULL)  prevX->next = currY;  
	else head_ref = currY;  
  
	if (prevY != NULL)  prevY->next = currX;  
	else head_ref = currX;  
  
	node *temp = currY->next;  
	currY->next = currX->next;  
	currX->next = temp;  
    
    return head_ref;
}
node* swap_nodes(node *head,int i,int j){
    int x,y;
    node *temp=head;
    int count=0;
    while(temp!=NULL){
        if(count == i-1){
            x = temp->next->data;
        }
        if(count == j-1){
            y = temp->next->data;
        }
        if( i==0 ) x = head->data;
        if( j==0 ) y = head->data;
        count++;
        temp = temp->next;
    }   
    if(x==y) return head;
    return swap_help( head, x, y);
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
    int i,j;
    node* head =takeinput();
    cin>>i;
    cin>>j;
    head=swap_nodes(head,i,j);
    print(head);
    return 0;
}

