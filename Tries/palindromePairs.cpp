#include <bits/stdc++.h>
using namespace std;
#include <string>
#include <vector>

class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie
{
    TrieNode *root;

public:
    int count;

    Trie()
    {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool add(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            if (!root->isTerminal)
            {
                root->isTerminal = true;
                return true;
            }
            else
            {
                return false;
            }
        }

        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        return add(child, word.substr(1));
    }

    void add(string word)
    {
        if (add(root, word))
        {
            this->count++;
        }
    }    
	bool search( TrieNode* root , string word ){
        if( word.size() == 0 ){
            if ( root->isTerminal ) return true;
            return false;
        }
        int index = word[0]-'a';
        if( root->children[index] ){
            return search( root->children[index] , word.substr(1) );
        }
        return false;
    }
    bool ispalindrome(string str){
         int i = 0;
         int j = str.size() - 1; 
         while(i < j) {
             if(str[i++] != str[j--]) return false;
         }
         return true;
    }
    bool isPalindromePair(vector<string> words)
    {
		for( auto x : words ){
            reverse( x.begin() , x.end() );
            add( x );
        }
        for( auto x : words ){
            if( search( root , x ) ) return true;
            else{
                for( int i = 0 ; i < x.length() ; i++ ){
                    string left = x.substr(0,i);
                    string right = x.substr(i);
                    if( ispalindrome( left ) ){
                        if( search( root , right ) ) return true;
                    }
                    if( ispalindrome( right ) ){
                        if( search( root , left ) ) return true;
                    }
                }
            }
        }
        return false;
    }

};
int main()
{
	Trie t;
	int n;
	cin >> n;
	vector<string> words(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> words[i];
	}
	bool ans = t.isPalindromePair(words);

	if (ans)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
}