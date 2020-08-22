#include <iostream>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define mod 1000000007 
using namespace std;
#include<map>

int noofvow[101];
string textrep[101];

void textrepmaker(){
    textrep[0] = "zero";
    textrep[1] = "one";
    textrep[2] = "two";
    textrep[3] = "three";
    textrep[4] = "four";
    textrep[5] = "five";
    textrep[6] = "six";
    textrep[7] = "seven";
    textrep[8] = "eight";
    textrep[9] = "nine";
    textrep[10] = "ten";
    textrep[11] = "eleven";
    textrep[12] = "twelve";
    textrep[13] = "thirteen";
    textrep[14] = "fourteen";
    textrep[15] = "fifteen";
    textrep[16] = "sixteen";
    textrep[17] = "seventeen";
    textrep[18] = "eighteen";
    textrep[19] = "nineteen";
    textrep[20] = "twenty";
    textrep[30] = "thirty";
    textrep[40] = "forty";
    textrep[50] = "fifty";
    textrep[60] = "sixty";
    textrep[70] = "seventy";
    textrep[80] = "eighty";
    textrep[90] = "ninety";
    textrep[100]= "hundred";
    for (int i = 0; i < 101; i++){
	    cout<<textrep[i]; 
    } 
}
void fillvowels(){
    for (int i = 0; i < 101; i++){
	    noofvow[i] = 0;
    }   
    noofvow[0] = 2;
    noofvow[1] = 2;
    noofvow[2] = 1;
    noofvow[3] = 2;
    noofvow[4] = 2;
    noofvow[5] = 2;
    noofvow[6] = 1;
    noofvow[7] = 2;
    noofvow[8] = 2;
    noofvow[9] = 2;
    noofvow[10] = 1;
    noofvow[11] = 3;
    noofvow[12] = 2;
    noofvow[13] = 3;
    noofvow[14] = 4;
    noofvow[15] = 3;
    noofvow[16] = 3;
    noofvow[17] = 4;
    noofvow[18] = 4;
    noofvow[19] = 4;
    noofvow[20] = 1;
    noofvow[30] = 1;
    noofvow[40] = 1;
    noofvow[50] = 1;
    noofvow[60] = 1;
    noofvow[70] = 2;
    noofvow[80] = 2;
    noofvow[90] = 2;
    noofvow[100] = 2;
}
int main() {
    textrepmaker();
    fillvowels();
    int n;
    cin>>n;
    int Dvalue = 0;
    int arr[n];
    map<int,int> m;
    for( int i=0 ; i<n ; i++){
        cin>>arr[i];
        m[arr[i]]++;
        int quotient = arr[i]/10;
        int reminder = arr[i]%10;
        if( quotient==1 or quotient==0 or reminder==0 ){
            Dvalue += noofvow[arr[i]];
        }
        else{
            quotient= quotient* 10;
            int ans = noofvow[quotient] + noofvow[reminder];
            Dvalue += ans;
        }
    }
    int count = 0;
    for(int i=0;i<n;i++){
        if( m[Dvalue - arr[i]] ){
            count += m[Dvalue-arr[i]];
        }
    }
    count = count/2;
    int quotient = count/10;
    int reminder = count%10;
    if( quotient==1 or quotient==0 or reminder==0 ){
        cout<<textrep[count];
    }
    else{
        quotient= quotient* 10;
        cout<<textrep[quotient]<<textrep[reminder];
    }
  	return 0;
}