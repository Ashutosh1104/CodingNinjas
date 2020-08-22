#include <iostream>
#include "treeNode.h"

int main(){
    treeNode<int>* root = new treeNode< int >(2);
    treeNode<int>* c11 = new treeNode< int >(1);
    treeNode<int>* c12 = new treeNode< int >(4);
    treeNode<int>* c13 = new treeNode< int >(3);

    root->setChildren( { c11 , c12 } );
    c12->setChildren( { c13 } );

    treeNode<int>* temp = root;
    cout<<temp->data<<endl;
    for(int i =0 ; i < temp->children.size() ; i++){
        cout<<temp->children[i]->data<<"\t";
    }
    cout<<endl;
    cout<<temp->children[1]->children[0]->data;
}