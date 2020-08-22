#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void removeConsecutiveDuplicates(char *input) {
	if(input[0]=='\0') return;
    int sc=0,j=0;
    while(input[sc]==input[0]){
        sc++;
    }
    cout<<input<<" "<<input[0]<<" "<<sc<<"\t";
    j=sc-1;
    for(int i=1;input[i]!='\0';i++){
        input[i]=input[i+j];
    }
    cout<<input<<endl;
    removeConsecutiveDuplicates(input+1);
}

int main() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}