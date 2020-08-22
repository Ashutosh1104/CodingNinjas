#include <bits/stdc++.h>
using namespace std;
int countStepsToOne(int n)
{
    if( n <= 1 ) return 0;
    if( n <= 3 ) return 1;
	vector<int> v(n+1,0);
    v[2]=1;
    v[3]=1;
    for( int i = 4 ; i <= n ; i++ ){
        int minimum = v[i-1];
        if( i % 2 == 0 ){
            minimum = min( v[i/2] , minimum ); 
        }
        if( i % 3 == 0 ){
            minimum = min( v[i/3] , minimum ); 
        }
        v[i] = minimum+1;
    }
    return v[n];
}

int main()
{
	int n;
	cin >> n;
	cout << countStepsToOne(n);
}
