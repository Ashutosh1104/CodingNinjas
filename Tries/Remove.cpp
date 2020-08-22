#include <iostream>
#include <string>
using namespace std;
#include <string.h>

class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

class Trie {
    TrieNode *root;
    
    public :
    
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insertWord(TrieNode *root, string word) {
        // Base case
        if(word.size() == 0) {
            root -> isTerminal = true;
            return;
        }
        
        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        }
        else {
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }
        
        // Recursive call
        insertWord(child, word.substr(1));
    }
    
    // For user
    void insertWord(string word) {
        insertWord(root, word);
    }
    
    bool searchUtil(TrieNode* root , string word) {
        if( word.length() == 0){
            if( root -> isTerminal ) return true;
            else return false;
        }       
        int index = word[0]-97;
        if( root->children[index] ){
            return searchUtil( root->children[index] , word.substr(1) );
        }
        else{
            return false;
        }
    }
    bool search(string word){
        return searchUtil( root, word );
    }

    void remove(TrieNode* root , string word) {
        if( word.length() == 0){
            root->isTerminal = false;
            return;
        }       
        int index = word[0]-97;
        if( root->children[index] ){
            return remove( root->children[index] , word.substr(1) );
        }
    }
    void remove(string word){
        return remove( root, word );
    }
};
int main() {
	int choice;
	cin >> choice;
	Trie t;
    t.insertWord("and");
    t.insertWord("andy");
    cout<<t.search("and")<<endl;
    cout<<t.search("andy")<<endl;
    t.remove("and");
    cout<<t.search("and")<<endl;
    cout<<t.search("andy")<<endl;
	return 0;
}
