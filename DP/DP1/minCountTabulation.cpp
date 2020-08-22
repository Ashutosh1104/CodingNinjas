#include <iostream>
#include <climits>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int minCount(int n){
	int dp[n+1];
    for( int i = 0 ; i <= n ; i++ ) dp[i]=0;
    dp[0]=0;
    dp[1]=1;
    for( int i = 2 ; i <= n ; i++ ){
        dp[i] = INT_MAX;
        for( int j = 0 ; (j*j) <= i ; j++ ){
            dp[i] = min( dp[i] , dp[i-(j*j)] );
        }
        dp[i]++;
    }
    return dp[n];
}
int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}