// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubsetWithZeroSum(int* arr, int size){
  	int sum = 0 , maxlen = INT_MIN;
  	for( int i = 0 ; i< size ; i++){
        if( arr[i] == 0 ) arr[i] = -1;
    }
    map <int,int> m;
    for( int i = 0 ; i < size ; i++){
        sum = sum + arr[i];
        cout<<sum<<" ";
        if( sum == 0 ) maxlen = max( maxlen , i+1 );
        if( m[ sum ] ){
            maxlen = max( maxlen , i-m[sum] );
        }
        else m[sum] = i ;
    }
    return maxlen;
}
int maxLen(int arr[], int N)
{
    return lengthOfLongestSubsetWithZeroSum( arr, N );
}
int main()
{
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << maxLen(a, n) << endl;
    }
    return 0;
}
