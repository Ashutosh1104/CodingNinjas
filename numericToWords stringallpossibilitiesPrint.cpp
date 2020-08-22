#include <string.h>
#include <iostream>
using namespace std;
void all(string input,string output){
    if(input[0]=='\0'){
        cout<<output<<endl;
        return;
    }
    output=output+(char)(input[0]-48+96);
    all(input.substr(1),output);
    int b=((int)input[0]-48)*10+((int)input[1]-48);
    if(b>0 && b<27){
        //cout<<output<<endl;
        output=output.substr(0, output.length() - 1);
        output=output+(char)(b+96);
        //cout<<output<<endl;
        all(input.substr(2),output);
    }
}
void printAllPossibleCodes(string input) {
    string output="";
    all(input,output);
}

int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
