#include<iostream>
#include<map>
#include<string>
using namespace std;
char* uniqueChar(char *s){
    char * c = new char[1000000];
    map<char,int> m ;
    int j = 0;
	for( int i =0 ; s[i] != '\0' ; i++){
        if( m[ s[i] ] == 0 ){
            c[j++] = s[i]; 
        }
        m[ s[i] ] = 1;                
    }
    c[j]='\0';
    return c;
}
int main() {
	char input[1000000];
	cin >> input;
	cout << uniqueChar(input) << endl;
}
