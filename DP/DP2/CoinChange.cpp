#include<iostream>
using namespace std;


int countWaysToMakeChange(int denominations[], int numDenominations, int value){
    int n = value+1;
    int dp[value+1]; // making do in o(n) space for better complexity
    for( int i = 0 ;i< n ; i++ ) dp[i] = 0 ;
    dp[0]=1;
    
    for( int i = 0 ; i< numDenominations ; i++ ){
        for( int j = denominations[i] ; j <= n ; j++ ){ // j starts from den[i] because till j<den[i] it cannot cause any change as the denom is larger than the value itself
            dp[j] = dp[j] + dp[ j - denominations[i] ];
        }
    }
    return dp[ n ];
}

int main(){

  int numDenominations;
  cin >> numDenominations;
  int* denominations = new int[numDenominations];
  for(int i = 0; i < numDenominations; i++){
    cin >> denominations[i];
  }
  int value;
  cin >> value;

  cout << countWaysToMakeChange(denominations, numDenominations, value);

}


