#include <iostream>
using namespace std;
#include<vector>
long staircase(int n)
{
    if( n < 3 ) return n;
    if( n == 3 ) return 4;
	vector< long > v(n+1,0);
    v[0]= 0;
    v[1]= 1;
    v[2]= 2;
    v[3]= 4;
    
    for( int i = 4 ; i <= n ;i++ ){
        v[i] = v[i-1]+v[i-2]+v[i-3];
    }
    
    return v[n];
}
int main()
{
	int n;
	cin >> n;
	cout << staircase(n);
}
