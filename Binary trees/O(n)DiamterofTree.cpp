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

using namespace std;
#include <utility> 
pair< int , int > heightDiameter(BinaryTreeNode<int>* root) {
	if (root == NULL) {
        pair<int,int>p;
        p.first = 0;
        p.second = 0;
		return p;
	}
    pair< int , int > leftAns = heightDiameter( root->left );
    pair< int , int > rightAns = heightDiameter( root->right );
	
    int ld = leftAns.second;
    int lh = leftAns.first;
    int rd = rightAns.second;
    int rh = rightAns.first;
    
    pair<int,int>res;
    res.first = 1+max(rh,lh); //overallDia
    res.second = max( rh+lh , max( ld , rd ) );
    
    return res;
}

int diameter(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return 0;
    }
	return heightDiameter( root ).second;
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

void printLevelATNewLine(BinaryTreeNode<int> *root) {
	queue<BinaryTreeNode<int>*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()) {
		BinaryTreeNode<int> *first = q.front();
		q.pop();
		if(first == NULL) {
			if(q.empty()) {
				break;
			}
			cout << endl;
			q.push(NULL);
			continue;
		}
		cout << first -> data << " ";
		if(first -> left != NULL) {
			q.push(first -> left);
		}
		if(first -> right != NULL) {
			q.push(first -> right);
		}
	}
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout<<diameter(root);
    delete root;
}
