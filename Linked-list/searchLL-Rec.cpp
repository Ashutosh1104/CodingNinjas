#include <iostream>
#include"node.h"
using namespace std;
int indexOfNRecursive(node *head, int n) {
    if( head->data == n ) return 0;
    if( head == NULL ) return -1;
    int count = indexOfNRecursive( head->next, n);
    
    if( count == -1 ) return -1;
    return count+1;
}

node* takeinput() {
    int data;
    cin >> data;
    node* head = NULL, *tail = NULL;
    while(data != -1){
        node *newnode = new node(data);
        if(head == NULL)                  {
            head = newnode;
            tail = newnode;
        }
        else{
            tail -> next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}

void print(node *head) {
    node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main() {
    node *head = takeinput();
    int n;
    cin >> n;
    cout << indexOfNRecursive(head, n);
    
}

