#include <iostream>
using namespace std;

template <typename T>

class BinaryTreeNode{
public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    
    BinaryTreeNode( T data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    ~BinaryTreeNode(){
        // Before deltetion every node delete left and right if left and right are NULL no issue as delete NULL is trivial and is ignored
        delete left;
        delete right;        
    }
};