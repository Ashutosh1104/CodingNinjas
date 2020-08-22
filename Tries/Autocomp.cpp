#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

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
	int count;

	Trie() {
		this->count = 0;
		root = new TrieNode('\0');
	}

	bool insertWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			if (!root->isTerminal) {
				root -> isTerminal = true;
				return true;	
			} else {
				return false;
			}
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
		return insertWord(child, word.substr(1));
	}

	// For user
	void insertWord(string word) {
		if (insertWord(root, word)) {
			this->count++;
		}
	}
    bool autoCompleteUtil( TrieNode* root , string pattern , vector<string> &res , string &pat ){ 
        if( pattern.size() == 0 ){
            if( root->isTerminal ){
                res.push_back(pat);
            }
            stack<TrieNode*> s;
            for( int i= 0 ; i<26 ; i++ ){
                if( root->children[i] ) s.push( root->children[i] );
            }
            string temp = pat; 
            while( !s.empty() ){
                TrieNode* t = s.top();
                temp += t->data;
                s.pop();
                int childCount = 0;
                for( int i= 0 ; i<26 ; i++ ){
                	if( t->children[i] ){ 
                        childCount++;
                        s.push( t->children[i] );
                    }
            	}
                if( childCount == 0 || t->isTerminal ){
                    cout<<temp<<endl;
                    temp = temp.substr(0,temp.length()-1);
                }
            }
            return true;
        }
        int index = pattern[0]-97;
        if( root->children[index] ){
            autoCompleteUtil( root->children[index] , pattern.substr(1) , res , pat );
        }
        else return false;
    }
    void autoComplete(vector<string> input, string pattern) {
        for( auto &x : input ){
            insertWord(x);
        }
        vector<string> res;
        if( autoCompleteUtil( root , pattern , res , pattern ) ){
            for( auto& x : res ){
                cout<<x<<endl;
            }
        }
        else cout<<"doesnt exists";
    }
};

int main() {
	Trie t;
    int N;
    cin >> N;
    string pattern;
    vector<string> vect;
    for (int i=0; i < N; i++) {
        string word;
        cin >> word;
        vect.push_back(word);
    }
    cin >> pattern;
    t.autoComplete(vect, pattern);
}
