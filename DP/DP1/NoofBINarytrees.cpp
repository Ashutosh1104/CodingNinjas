#include <iostream>
using namespace std;
#define mod 1000000007
#define ll long long
int minCount(int n){
	ll int h[n+2];
    for( ll int i = 0 ; i <= n+1 ; i++ ) h[i]=0;
    h[1]=1;
    h[2]=3;
    for( ll int i = 2 ; i <= n+1 ; i++ ){
        h[i] = h[i-1]*h[i-1] + 2 * ( h[i-1]*h[i-2] ); 
    }
    return h[n+1] % mod;
}
int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}