#include <vector>
#include <iostream>
#include <string>
using namespace std;
#define ll long long
#define mod 1000000007

bool isPalindrome(string &str , int left , int right ) 
{ 
    while ( right > left) { 
        if (str[left] != str[right]) return false; 
        left++;
        right--;
    } 
    return true; 
} 
int main()
{
    string s;
    cin>>s;
    bool flag = false;
    for( ll int i = 1 ; i < (ll int)s.length()-2 ; i++ ){
        if( isPalindrome( s , 0 , i ) ){
            for( ll int j = i+1 ; j < (ll int)s.length()-2 ; j++ ){
                if( isPalindrome( s , i+1 , j )  , isPalindrome( s ,j+1 ,(ll int)s.length()-1 ) ){
                    flag = true;
                    string x = s.substr(0,i+1);
                    string y = s.substr(i+1,j-i);
                    if( j==2 ){
                        string temp = x;
                        x =y;
                        y =temp;
                    }
                    string z = s.substr(j+1);
                    cout<<x<<endl<<y<<endl<<z<<endl;
                }
            }
        }
    }
    if(!flag) cout<<"not possible";
}