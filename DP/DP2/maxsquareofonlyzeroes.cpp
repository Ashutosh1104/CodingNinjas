#include<iostream>
#include<algorithm> 
using namespace std;
int findMaxSquareWithAllZeros(int** arr, int row, int col){
    int dp[row][col];
	int max = 0 ;
    for( int i = 0 ; i < col ; i++ ){
        if( arr[0][i] == 0 ){ 
            dp[0][i] = 1;
            max = 1;
        }
        else dp[0][i] = 0;
    }
    for( int i = 0 ; i < row ; i++ ){
        if( arr[i][0] == 0 ){
            dp[i][0] = 1;
            max = 1;
        }
        else dp[i][0] = 0;
    }
    
    for( int i = 1 ; i < row ; i++ ){
        for( int j = 1 ; j < col ; j++ ){        
            if( arr[i][j] == 0 ){
            	dp[i][j] = min ( dp[i-1][j-1] , min( dp[i-1][j] , dp[i][j-1] ) )+1;
            	if(dp[i][j] > max) max = dp[i][j];
            }
            else dp[i][j] = 0;
        }
    }
    return max;
}
int main()
 {
  int **arr,n,m,i,j;
  cin>>n>>m;
  arr=new int*[n];
  for(i=0;i<n;i++)
      {
       arr[i]=new int[m];
      }
  for(i=0;i<n;i++)
     {
      for(j=0;j<m;j++)
	    {
	     cin>>arr[i][j];
	    }
     }
  cout << findMaxSquareWithAllZeros(arr,n,m) << endl;
  delete arr;
  return 0;
}