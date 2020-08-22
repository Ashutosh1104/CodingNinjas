#include <string>
#include <iostream>
using namespace std;

#include <string>
using namespace std;
string* s = new string[10] { "","","abc", "def" ,"ghi","jkl","mno","pqrs","tuv","wxyz"};
int keypad(int num, string output[]){
    if(num==0 || num==1){
        output[0]="";
        return 1;
    }
    int no=keypad(num/10,output);
    int left=num%10;
    int copies=s[left].size(); 
    for(int i=1;i<copies;i++){
        for(int j=0;j<no;j++){
            output[no*i+j]=output[j];
        }
    }
    for(int i=0;i<copies*no;i++){
		output[i]=output[i]+s[left][i/no];
    }
    return copies*no;
}

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
