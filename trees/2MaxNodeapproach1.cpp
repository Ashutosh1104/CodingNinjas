#include <iostream>
using namespace std;
#include <vector>

template <typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T>*> children;
    
    TreeNode(T data) {
        this->data = data;
    }
    
    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
    
};


#include <queue>
TreeNode<int>* maxSumNode(TreeNode<int> *root){
    TreeNode<int>* max = root;
    int maxSum = 0;
    
    maxSum = root->data;
	for( int i = 0; i < root->children.size() ; i++ ){
        maxSum +=root->children[i]->data;
    }
    
    for( int i = 0; i < root->children.size() ; i++ ){
        TreeNode<int>* subTree = maxSumNode( root->children[i] );
        int subTreeSum = subTree->data;
        for( int i = 0; i < subTree->children.size() ; i++ ) subTreeSum += subTree->children[i]->data;
        
        cout<<subTreeSum<<" "<<maxSum<<endl;
        if( subTreeSum >= maxSum ){
            max = subTree;
            maxSum = subTreeSum;
        }
    }
    
    return max;
}


TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    
    queue<TreeNode<int>*> pendingNodes;
    
    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = maxSumNode(root);
    if(ans != NULL) {
        cout << ans -> data << endl;
    }
}


