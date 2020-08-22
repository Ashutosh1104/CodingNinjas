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
BinaryTreeNode<int>* buildTreeUtil(int *preOrder, int *inOrder, int inStart , int inEnd , int preStart , int preEnd ) {
    if( inStart > inEnd ) return NULL;
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>( preOrder[preStart] );
    
    int len = 0;
    while( preOrder[preStart] !=  inOrder[ inStart+len ] ){
        len++;
    }
    int rootIndex = inStart+len;
    int LinStart , LinEnd , LpreStart , LpreEnd , RinStart , RinEnd , RpreStart , RpreEnd;
    LinStart = inStart;
    LinEnd = rootIndex-1; 
    LpreStart = preStart+1;
    LpreEnd = LinEnd - LinStart + LpreStart ;

    RinStart = rootIndex+1;
    RinEnd = inEnd; 
    RpreStart = LpreEnd+1;
    RpreEnd = preEnd ;

    root->left = buildTreeUtil( preOrder , inOrder , LinStart , LinEnd , LpreStart , LpreEnd );
    root->right= buildTreeUtil( preOrder , inOrder , RinStart , RinEnd , RpreStart , RpreEnd );
    
    return root;
}
BinaryTreeNode<int>* buildTree(int *preorder, int preLenght, int *inorder, int inLength) {
    return buildTreeUtil( preorder , inorder , 0 , inLength-1 , 0 , preLenght-1 );
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
    int *pre = new int[size];
    int *in = new int[size];
    for(int i=0;i<size;i++)
		cin>>pre[i];
    for(int i=0;i<size;i++)
		cin>>in[i];
    BinaryTreeNode<int>* root = buildTree(pre, size, in, size);
    printLevelATNewLine(root);
}
