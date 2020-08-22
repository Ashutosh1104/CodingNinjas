#include "1BtreeNode.h"
#include<queue>
#include<stack>

BinaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cin>>rootData;
    if( rootData == -1 ) return NULL;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    
    queue< BinaryTreeNode<int>* > pendingNodes;
    pendingNodes.push(root);

    while( !pendingNodes.empty() ){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        int left , right ;
        cin>>left>>right;
        if( left != -1 ){
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(left);
            front->left = leftNode;
            pendingNodes.push(leftNode);
        }
        if( right != -1 ){
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(right);
            front->right = rightNode;
            pendingNodes.push(rightNode);
        }  
    }
    return root;
}   
//This is post order 
void printBinaryTreeLevelWisePO( BinaryTreeNode<int>* root ){
    if( root == NULL ) return;

    queue< BinaryTreeNode<int>* > pendingNodes;
    pendingNodes.push(root);

    while( !pendingNodes.empty() ){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        int left , right ;
        if( front->left ){ 
            pendingNodes.push(front->left);
            left = front->left->data;
        }
        else left =-1;
        if( front->right ){ 
            pendingNodes.push(front->right);
            right = front->right->data;
        }
        else right =-1;
        cout<<front->data<<":L:"<<left<<",R:"<<right<<endl;
        root = front;
    }    
}
int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    printBinaryTreeLevelWisePO(root);
    cout<<endl;
    //printBinaryTreeLevelWiseIO(root);
}
// Enter -1 for no child 