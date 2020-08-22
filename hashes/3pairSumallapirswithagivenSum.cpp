#include <bits/stdc++.h>
using namespace std;
void pairSum(int *input, int n) 
{
    int sum = 4;
    map < int , int > m;
    for( int i = 0 ; i < n ; i++ ){
        if( m[ sum - input[i] ] ){
            for( int j = 0 ; j < m[ sum - input[i] ] ; j++ ){
                int p = min( input[i] , sum -input[i] );
                int q = max( input[i] , sum -input[i] );
                cout<<p<<" "<<q<<endl;
            }
        }
        m[ input[i] ]++;
    }
}

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	pairSum(arr, n);

	delete[] arr;

	return 0;
}