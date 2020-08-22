#include<iostream>
#include <string>
using namespace std;
string* s = new string[10] { "","","abc", "def" ,"ghi","jkl","mno","pqrs","tuv","wxyz"};
void keypad(int num, string output){
    if(num==0 || num==1){
        cout<<output<<endl;
        return;
    }
    int left=num%10;
    int copies=s[left].size();
    for(int i=0;i<copies;i++){
        //cout<<(num/10)<<" "<<s[left][i]<<endl;
        keypad(num/10,s[left][i]+output);
    }
}

int main(){
    int num;
    cin >> num;

    string output;
    keypad(num, output);
    return 0;
}
