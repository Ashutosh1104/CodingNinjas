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
BinaryTreeNode<int>* buildTreeUtil(int *postOrder, int *inOrder, int inStart , int inEnd , int postStart , int postEnd ) {
    if( inStart > inEnd ) return NULL;
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>( postOrder[postEnd] );
    
    int len = 0;
    while( postOrder[postEnd] !=  inOrder[ inStart+len ] ){
        len++;
    }
    int rootIndex = inStart+len;
    int LinStart , LinEnd , LpostStart , LpostEnd , RinStart , RinEnd , RpostStart , RpostEnd;
    
    LinStart = inStart;
    LinEnd = rootIndex-1; 
    LpostStart = postStart;
    LpostEnd = LinEnd - LinStart + LpostStart ;

    RinStart = rootIndex+1;
    RinEnd = inEnd; 
    RpostStart = LpostEnd+1;
    RpostEnd= postEnd - 1 ;

    root->left = buildTreeUtil( postOrder , inOrder , LinStart , LinEnd , LpostStart , LpostEnd );
    root->right= buildTreeUtil( postOrder , inOrder , RinStart , RinEnd , RpostStart , RpostEnd );
    
    return root;
}
BinaryTreeNode<int>* getTreeFromPostorderAndInorder(int *postorder, int postLength, int *inorder, int inLength) {
    return buildTreeUtil( postorder , inorder , 0 , inLength-1 , 0 , postLength-1 );
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
    int size;
    cin >> size;
    int *post = new int[size];
    int *in = new int[size];
    for(int i=0;i<size;i++)
		cin>>post[i];
    for(int i=0;i<size;i++)
		cin>>in[i];
    BinaryTreeNode<int>* root = getTreeFromPostorderAndInorder(post, size, in, size);
    printLevelATNewLine(root);
}
