#include <iostream>
#include <vector>
#include <queue>

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
using namespace std;
vector<int>* height(BinaryTreeNode<int> *root) {
    if( root == NULL ){
        vector<int>* v = new vector<int>; 
        return v;
    }
    vector<int>* v1 = height( root->left );
    vector<int>* v2 = height( root->right );
    v1->push_back( root->data );
    v2->push_back( root->data );
    if( v1->size() > v2->size() ){
        return v1;
    }
    return v2;
}
vector<int>* longestPath(BinaryTreeNode<int>* root) {
	return height( root );    
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
    vector<int> *output = longestPath(root);
    vector<int> :: iterator i = output -> begin();
    while(i != output -> end()) {
    	cout << *i << endl;
    	i++;
    }
}
