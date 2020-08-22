#include <iostream>
#include <string.h>
using namespace std;

int getCodes(string input, string output[10000]) {
    if(input[0]=='\0'){
        return 1;
    }
    string o1[10000],o2[10000];
    int l1=0,l2=0,row=0;
    l1=getCodes(input.substr(1),o1);
    for(int i=0;i<l1;i++){
        string a="";
        a=a+(char)(input[0]-48+96);
        a.append(o1[i]);
        output[row++]=a;
    }
    int b=((int)input[0]-48)*10+((int)input[1]-48);
    if(b>0 && b<27){
        l2=getCodes(input.substr(2),o2);
        for(int i=0;i<l2;i++){
        	string m="";
        	m=m+(char)(b+96);
        	m.append(o2[i]);
            output[row++]=m;
        }
    }
    return l1+l2;
}

int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}
