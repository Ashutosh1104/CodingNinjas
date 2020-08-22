#include <iostream>
using namespace std;
#include<string.h>

int lis(int arr[], int n) {
	int dp[n+1];
    for( int i = 0 ; i <= n ; i++ ) dp[i]=1;
     
    for( int i = 1 ; i <= n ; i++ ){
        int j=0;
        while( j++ < i ){
            if( arr[j]<arr[i] ) dp[i]=max( dp[i] , dp[j]+1);
        }
    }    
    int res = 1;
    for( int i = 0 ; i < n ; i++ ){
        res = max ( res , dp[i] );
    }
     
    return res;
}
int main(){
    int n;
    cin >> n;
    int arr[100000];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << lis(arr, n);
}

