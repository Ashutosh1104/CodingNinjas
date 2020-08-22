#include <iostream>
#include "treeNode.h"

void printTree( treeNode<int>* root ){
    if( !root ) return; //this handles edge case that is empty tree no need for just base
    cout<<root->data<<" : ";

    for(int i =0 ; i < root->children.size() ; i++){   // toknow who is the child of whom 
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    //recursive call
    for(int i =0 ; i < root->children.size() ; i++){
        printTree( root->children[i] );
    }
}

int main(){
    treeNode<int>* root = new treeNode< int >(2);
    treeNode<int>* c11 = new treeNode< int >(1);
    treeNode<int>* c12 = new treeNode< int >(4);
    treeNode<int>* c13 = new treeNode< int >(3);


    root->setChildren( { c11 , c12 } );
    c12->setChildren( { c13 } );

    printTree(root);
}