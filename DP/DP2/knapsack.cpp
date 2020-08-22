#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
int knapsackSpaceOptimized(int* weights, int* values, int n , int maxWeight){
    int dp[2][maxWeight+1];
    for( int i = 0 ; i < 2 ; i++ ){
    	for( int j = 0 ; j <= maxWeight ; j++ ) dp[i][j] = 0;
    }
    
    for( int i = 1 ; i <= n ; i++ ){
        if( i% 2 != 0 ){
            for( int j = 1 ; j <= maxWeight ; j++ ){
                if( j >= weights[i-1] ){
                	dp[1][j] = max ( values[i-1]+ dp[0][ j - weights[i-1] ] , dp[0][j] );
            	}
            	else dp[1][j] = dp[0][j];
            }
        }
        else{
            for( int j = 1 ; j <= maxWeight ; j++ ){
                if( j >= weights[i-1] ){
                	dp[0][j] = max ( values[i-1] + dp[1][ j - weights[i-1] ] , dp[1][j] );
            	}
            	else dp[0][j] = dp[1][j];
            }
        }
    }
    return (n%2 != 0)? dp[0][maxWeight] : dp[1][maxWeight];
}
using namespace std;
int knapsackDP(int* weights, int* values, int n , int maxWeight){
    int dp[n+1][maxWeight+1];
    for( int i = 0 ; i <= n ; i++ ){
    	for( int j = 0 ; j <= maxWeight ; j++ ) dp[i][j] = 0;
    }
    
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= maxWeight ; j++ ){
            if( j >= weights[i-1] ){
                dp[i][j] = max ( values[i-1] + dp[i-1][ j - weights[i-1] ] , dp[i-1][j] );
            }
            else dp[i][j] = dp[i-1][j];
            cout<<dp[i][j];
        }
        cout<<endl;
    }
    return dp[n][maxWeight];
}

int knapsackbrute(int* weights, int* values, int n , int maxWeight , vector<int> v , int val ){
    //all posiiblities along with all values and max value
	if( n == 0 || maxWeight == 0 ){
        cout<<val<<" : ";
        for( auto x : v ){
            cout<<x<<" ";
        }
        cout<<endl;
        return val;
    }  
    if( maxWeight < weights[0] ){
      return knapsackbrute( weights+1 , values+1 , n-1 , maxWeight , v , val );
    }
    int x = knapsackbrute( weights+1 , values+1 , n-1 , maxWeight , v , val ); // no
    v.push_back(weights[0]);
    int y = knapsackbrute( weights+1 , values+1 , n-1 , maxWeight-weights[0] , v , val+values[0] ); //yes
    
    return max(x,y);
}

int main() {
	int n; 
	cin >> n;
	int* weights = new int[n];
	int* values = new int[n];

	for(int i = 0; i < n; i++){
		cin >> weights[i];
	}

	for(int i = 0; i < n; i++){
		cin >> values[i];
	}

	int maxWeight;
	cin >> maxWeight;
	vector<int> v;
	cout<<knapsackSpaceOptimized(weights, values, n, maxWeight);
}