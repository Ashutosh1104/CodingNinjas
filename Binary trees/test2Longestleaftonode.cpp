#include <iostream>
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

    ~BinaryTreeNode() {
    	if(left) 
       		delete left;
    	if(right) 
       		delete right;
    }
};
#include<vector>
#include<map>
#include<set>
using namespace std;
vector<int> ans;   
map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> parent;
set<BinaryTreeNode<int>*> visit;
void findParent(BinaryTreeNode<int>* node){
        if(!node ) return;
        if( node->left ){
        parent[node->left] = node;
        findParent(node->left);
        }
    if( node->right){
        parent[node->right] = node;
        findParent(node->right);
    }
}
void dfs( BinaryTreeNode<int>* node, int K){
	if( visit.find(node) != visit.end() )
        return;
    visit.insert(node);
    if( K == 0 ){
        ans.push_back(node->data);
        return;
    }
    if( node->left ){
    	dfs(node->left, K-1);
    }
    if( node->right){
        dfs(node->right, K-1);
    }
    BinaryTreeNode<int>* p = parent[node];
    if( p )
        dfs(p, K-1);
}
BinaryTreeNode<int>* findTarget( BinaryTreeNode<int>* root, int targetNode){
    if( root == NULL ) return NULL;
    if( root->data == targetNode ){
        return root;
    }
    BinaryTreeNode<int>* left = findTarget( root->left , targetNode );
    BinaryTreeNode<int>* right = findTarget( root->right, targetNode );  

	if( left ) return left;
	if( right ) return right;
	return NULL;
}
vector<int> nodesAtDistanceK(BinaryTreeNode<int>* root, int targetNode, int K) {
    if( !root ) return {};
        
    findParent(root);
    BinaryTreeNode<int>* target = findTarget(root, targetNode);
    cout<<target<<endl;
    //dfs(target, K );
    return ans;
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
    int targetNode, k;
    cin >> targetNode >> k;
    nodesAtDistanceK(root, targetNode, k);
    delete root;
}
