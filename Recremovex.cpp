#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int len(char str[]){
    if(str[0]=='\0'){
        return 0;
    }
    return 1+len(str+1);
}
void remove(char input[],char x,int n){
    if(n==0) return;
    if(input[0]==x){
        for(int i=0;i<=n;i++){
            input[i]=input[i+1];
        }
        return remove(input,x,n-1);
    }
    return remove(input+1,x,n-1);        
}
int main()
{
	char str[100],rem;
    cin>>str>>rem;
    int l=len(str);
    remove(str,rem,l);
    cout<<str;
}