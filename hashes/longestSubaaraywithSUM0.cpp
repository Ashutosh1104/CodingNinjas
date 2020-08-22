#include<iostream>
#include<map>
#include<limits.h>
using namespace std;

int lengthOfLongestSubsetWithZeroSum(int* arr, int size){
  	int sum = 0 , maxlen = 0;
    map <int,int> m;
    m[ arr[0] ] = INT_MIN;
    for( int i = 0 ; i < size ; i++){
        sum = sum + arr[i];
        if( sum == 0 ) maxlen = max( maxlen , i+1 );
        else if( m.count(sum) ){
            maxlen = max( maxlen , i-m[sum] );
        }
        else m[sum] = i ;
    }
    return maxlen;
}

int main(){
  int size;
  
  cin >> size;
  int* arr = new int[size];
  for(int i = 0; i < size; i++){
    cin >> arr[i];
  }
  int ans = lengthOfLongestSubsetWithZeroSum(arr,size);
  cout << ans << endl;
  delete arr;
}


