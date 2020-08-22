#include <iostream>
#include <queue>
using namespace std;
int main()
{
	int n ,k;
    cin>>n>>k;
    int a[n];
    for( int i = 0 ; i< n ;i++){
        cin>>a[i];
    }
    
    priority_queue <int> pq;
    
    int i = 0;    
    while( i < k ) pq.push( a[i++] );
    
    int right = k;
    for( int i = 0 ; i < n ; i++ ){
        a[i] = pq.top();
        cout<<a[i]<<" ";
        pq.pop();
        if( right < n ){
         	pq.push( a[right] );   
        }
        right++;
    }    
}