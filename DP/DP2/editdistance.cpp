#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//Tabulation
int editDistanceTab( string s , string t ){
    int m = s.length() , n = t.length();
    
    int dp[m+1][n+1];
    dp[0][0]=0;
    for( int i = 1 ; i <= m ; i++ ) dp[i][0] = i;
	for( int i = 1 ; i <= n ; i++ ) dp[0][i] = i;
    
    for( int i = 1 ; i <= m ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            if( s[i-1] == t[j-1] ){
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = 1 + min( dp[i-1][j] , min ( dp[i][j-1] , dp[i-1][j-1]) );
            }
        }
    }
    return dp[m][n];
}
//MEMOIZATION
int editdistMem( string &s , string &t ,int i , int j ,vector<vector<int>>& dp ){
    if( i==0 || j==0 ){
        return max( i , j );
    }
    if( dp[i-1][j-1] ) return dp[i-1][j-1];
    
    if( s[i-1] == t[j-1] ){
        dp[i-1][j-1] = editdistMem( s , t , i-1 , j-1 , dp );
        return dp[i-1][j-1];
    }
    
    int a = editdistMem( s , t , i-1 , j-1 , dp ); //replace
    int b = editdistMem( s , t , i , j-1 , dp ); // remove
    int c = editdistMem( s , t , i-1 , j , dp ); //insert
    
    dp[i-1][j-1] = 1 + min( a, min(b,c) );
    return dp[i-1][j-1];
}
int editdistMem( string s , string t ){
    int i = s.length() ;
    int j = t.length() ;
    vector<vector<int>> dp ( s.length() , vector<int>(t.length(),0) );
    return editdistMem( s , t , i , j ,dp );
}

//RECURSIVE
int editdist( string s , string t  ){
    if( s.length()==0 || t.length()==0 ){
        return max( (int)s.length() , (int)t.length() );
    }
    if( s[0] == t[0] ){
        return editdist( s.substr(1) , t.substr(1) );
    }
    int a = editdist( s.substr(1) , t.substr(1) ); //replace
    int b = editdist( s , t.substr(1) ); // remove
    int c = editdist( s.substr(1) , t ); //insert
    
    return 1 + min( a, min(b,c) );
}

int main()
{
	string s , t ;
    cin>>s>>t;
    
    cout<<editDistanceTab(s,t);
}