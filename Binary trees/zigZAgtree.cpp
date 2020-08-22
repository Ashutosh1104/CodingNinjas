#include <iostream>
#include <queue>
#include <stack>

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
#include<queue>
#include<vector>
#include<algorithm>
void zigZagOrder(BinaryTreeNode<int> *root) {
    if( root == NULL ) return;
    
    queue<BinaryTreeNode<int> *> pendingNodes;
    vector<BinaryTreeNode<int> *> printIt;
    pendingNodes.push( root );
    pendingNodes.push( NULL );
    bool rev = false;
    while( pendingNodes.size() > 1 ){
        BinaryTreeNode<int> * front = pendingNodes.front();
        pendingNodes.pop();
        
        if( front == NULL ){
            if( rev ) reverse( printIt.begin() , printIt.end() );
            for( int i = 0 ; i < printIt.size() ; i++ ){
                cout<<printIt[i]->data<<" ";
            }
            cout<<"\n";
            rev = !rev;
            printIt.clear();
            pendingNodes.push( NULL );
        }
        else{
            printIt.push_back( front );
            if( front->left ) pendingNodes.push( front->left );
            if( front->right ) pendingNodes.push( front->right );
        }
    }
    if( rev ) reverse( printIt.begin() , printIt.end() );
    for( int i = 0 ; i < printIt.size() ; i++ ){
        cout<<printIt[i]->data<<" ";
    }
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    zigZagOrder(root);
}
