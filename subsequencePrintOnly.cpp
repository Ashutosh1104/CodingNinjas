#include <string>
#include <iostream>
using namespace std;
//The diffrence is here we send our choice first so we can print it instead of making it after rec. so we can either include input[0] or exclude it
void printsubs(string in, string out){
    if(in.empty()){
        cout<<out<<endl;
        return;
    }
    //for abc
    printsubs(in.substr(1),out); //output does not take a
    printsubs(in.substr(1),out+in[0]); // output does take a
}

int main(){
    string input;
    cin >> input;

    string output;
    printsubs(input, output);
    return 0;
}
