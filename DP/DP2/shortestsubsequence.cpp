#include<bits/stdc++.h>
using namespace std;
int solve(string S,string V){
	int n = S.length();
    int m = V.length();
    int dp[n+1][m+1];
    
    for( int i = 0 ; i <= n ; i++  ) dp[i][0] = 1;
    for( int i = 0 ; i <= m ; i++  ) dp[0][i] = 3000; // any max in which we can add some values so not INT_max as adding to it makes the no negative 
    
    for( int i = 1 ; i <= n ; i++  ){
        for( int j = 1 ; j <= m ; j++  ){
            int k;
            char ch = S[i-1];
            for (k = j-1; k >= 0; k--) 
                if (V[k] == ch) break; 
            
            if( k == -1 ) dp[i][j] = 1;
            
            else dp[i][j] = min ( dp[i-1][j] , dp[i-1][k]+1 );
        }
    }
    if( dp[n][m] == 3000 ) return 1000000000; 
    return dp[n][m];
}

int main()
{
	string S,V;
	cin>>S>>V;
	cout<<solve(S,V)<<endl;
	return 0;
}