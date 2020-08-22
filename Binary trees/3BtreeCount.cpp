#include "1BtreeNode.h"
#include<queue>
#include<stack>

int countNode(BinaryTreeNode<int>* root){
    if( root == NULL ) return 0;

    int leftSub=0,rightSub=0;
    if(root->left) leftSub = countNode(root->left);
    if(root->right) rightSub = countNode(root->right);

    return leftSub+rightSub+1;
}
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
void printBinaryTreeLevelWise( BinaryTreeNode<int>* root ){
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
    cout<<countNode(root);
}
