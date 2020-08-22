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
};

using namespace std;
class result{
public:
    BinaryTreeNode<int> * parent = NULL;
    int level = 9999;
};
void isCousinHelper(BinaryTreeNode<int> *root, int p, int q , BinaryTreeNode<int> *parent , int level , result *forp , result *forq ) {
	if( root == NULL ) return;
    
    if( root->data == p ){
        forp->parent =  parent;
        forp->level = level+1;
        //cout<<p<<" "<<parent->data<<" level "<<level<<endl;
    }
    if( root->data == q ){
        forq->parent =  parent;
        forq->level = level+1;
        //cout<<q<<" "<<parent->data<<" level "<<level<<endl;
    }
    isCousinHelper( root->left , p , q , root , level+1 ,forp , forq); 
    isCousinHelper( root->right , p , q , root , level +1 ,forp , forq);
}
bool isCousin(BinaryTreeNode<int> *root, int p, int q) {
    result *forp = new result;
    result *forq = new result;
	isCousinHelper( root , p , q , NULL , 1 , forp , forq);
    
    if( forp->level == forq->level && forp->parent != forq->parent) return true;
    else return false;
    //cout<<p<<" "<<forp->parent->data<<" "<<forp->level<<endl;
    //cout<<q<<" "<<forq->parent->data<<" "<<forq->level;
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
    int n1, n2;
    cin >> n1 >> n2;
    if(isCousin(root, n1, n2)) {
	    cout << "true" << endl;
    }
    else {
	    cout << "false" << endl;
    }
}
