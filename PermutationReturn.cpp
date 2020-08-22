#include <bits/stdc++.h>
#include <iostream>
using namespace std;
string stringmake(string old, char a ,int index){
    string s(1, a);
    return old.insert(index,s);
}
int place(string m[],char a,int size){
    cout<<a<<endl;
    string newm[10000];
    int count =0;
    for(int i=0;i<size;i++){
        int l=m[i].size()+1;
        for(int j=0;j<l;j++){
        	newm[count++]=stringmake(m[i],a,j);	
    	}
    }
    for(int i=0;i<count;i++) m[i]=newm[i];
    cout<<count<<endl;
    return count;
}
int returnPermutations(string input, string output[]){
   	if(input[0]=='\0'){
        return 1;
    }
    int m=returnPermutations(input.substr(1),output);
    return place(output,input[0],m);
}
int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
