#include <iostream>
using namespace std;

#include<string.h>
int max( int a, int b ){
    return a>b ? a : b;
}
#include<string.h>
int max( int a, int b ){
    return a>b ? a : b;
}
int getMaxMoney(int arr[], int n){
	int dp[n];
    memset ( dp ,0 , n );
    dp[0]=arr[0];
    dp[1]=max( arr[0] , arr[1]);
    for( int i = 2 ; i < n ; i++ ){
        dp[i] = max( dp[i-1] , dp[i-2]+arr[i] ) ;
    }
    
    return dp[n-1];
}


int main(){
    int n;
    cin >> n;
    int arr[10000];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << getMaxMoney(arr, n);
}

