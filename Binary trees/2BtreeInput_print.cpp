#include "1BtreeNode.h"

BinaryTreeNode<int>* takeInput(){
    int rootData;
    cin>>rootData;
    if( rootData == -1 ) return NULL;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* left = takeInput();
    BinaryTreeNode<int>* right = takeInput();

    root->left = left;
    root->right = right;
    return root;
}   
void printBinaryTree( BinaryTreeNode<int>* root ){
    if( root == NULL ) return;
    cout<<root->data<<" : ";
    if( root->left ) cout<<"L-Child = "<<root->left->data<<"\t,\t";
    if( root->right ) cout<<"R-child = "<<root->right->data;
    cout<<endl;
    printBinaryTree( root->left );
    printBinaryTree( root->right );
}
int main(){
    BinaryTreeNode<int>* root = takeInput();
    printBinaryTree(root);
}
