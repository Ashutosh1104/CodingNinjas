#include <iostream>
#include <climits>
#include <algorithm>
#include <cstring>
using namespace std;
int minCountUtil(int n , int* ans){
	if( ans[n] ) return ans[n];
        
    int temp = 1 , minimum =INT_MAX , curr=0;
    while( temp * temp <= n ){
        int curr = minCountUtil( n-temp*temp , ans );
        minimum = min ( curr , minimum );
        temp++;
    }
    ans[ n ] = minimum+1;
    return ans[n];
}
int minCount(int n){
	if( n == 1 || n == 4 || n == 9 ) return 1;
    int a[n+1];
    memset(a, 0, sizeof(a));
    int temp = 1 ;
    while( temp* temp <= n ){
        a[temp* temp]=1;
        temp++;
    }
    return minCountUtil( n , a );    
}
int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}
