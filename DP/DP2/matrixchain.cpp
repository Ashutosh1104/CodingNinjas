#include<iostream>
#include<climits>
using namespace std;

int mcm(int* arr, int n){
    n++; // one extra row
	int temp[n][n];
    for( int i = 1 ; i < n ; i++ ) temp[i][i] = 0 ;
       
    int i, j, k, l, q; 
    for( l=2; l < n ; l++){
        for( i = 1; i < n-l+1 ; i++){
            j = i+l-1;
            temp[i][j] = INT_MAX;
            for( k = i; k <= j-1 ; k++ ){
                q = temp[i][k] + temp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                if(q < temp[i][j]){
                    temp[i][j] = q;
                }
            }
        }
    }
    return temp[1][n-1];
} 

int main(){

  int n; 
  cin >> n;
  int* p = new int[n];

  for(int i = 0; i <= n; i++){
    cin >> p[i];
  }

  cout << mcm(p, n);

}


