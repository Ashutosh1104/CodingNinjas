#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void permutatation(string input,string output,int size){
    if(input[0]=='\0'){
        cout<<output<<endl;
        return;
    }    
    for(int i=0;i<size;i++){
        string x=output;
        string s(1,input[0]);
        x.insert(i,s);
        permutatation(input.substr(1),x,size+1);
    }
}

void printPermutations(string input){
    string output;
    permutatation(input,output,1);
}
int main(){
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}

