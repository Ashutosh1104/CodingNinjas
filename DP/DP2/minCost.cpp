#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minCostPath(int **input, int m, int n) {
    vector< vector<int> > dp( m, vector<int> (n,0) );
    dp[0][0] = input[0][0]; 
    for( int i = 1 ; i < m ; i++ ) dp[i][0] = dp[i-1][0]+input[i][0];
    for( int i = 1 ; i < n ; i++ ) dp[0][i] = dp[0][i-1]+input[0][i];
    
    for( int i = 1 ; i < m ; i++ ){
        for( int j = 1 ; j < n ; j++ ){
            int a = dp[i-1][j];
            int b = dp[i][j-1];
            int c = dp[i-1][j-1];
            int curr = min( a , min( b , c ) );
            dp[i][j] = curr+input[i][j]; 
        }
    }
    return dp[m-1][n-1];
}

int main() {
    int **arr,n,m;
    cin >> n >> m;
    arr = new int*[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    cout << minCostPath(arr, n, m) << endl;
}
