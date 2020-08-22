#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class TrieNode{
public:
  	char data;
    TrieNode** Children = new TrieNode*[26]; // just alphabets 
    bool isTerminal = false;
    
    TrieNode( char a ){
        this->data = a;
        isTerminal = false;
        Children = new TrieNode* [26];
        for( int i = 0 ; i < 26 ; i++ ) Children[i]= NULL;
    }
};