#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using namespace std;
int buyTicket (int *a, int n, int k){
    priority_queue< int > pq;
    queue<int> q;
    for( int i = 0 ; i < n ; i++ ){ 
        pq.push( a[i] );
        q.push( i );
    }
    
    int time = 0;
    while( !pq.empty() ){
        if( pq.top() == a[ q.front() ] ){
            if( q.front() == k ) return time+1;
            else{
                q.pop();
        		pq.pop();
        		time++;
            }
        }
        else{
        	int t = q.front();
        	q.push(t);
        	q.pop();
        	pq.pop();
        	time++;
        }
    }
    return time-1;
}
int main(){
    int n, k, s;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> k;
    cout << buyTicket(arr, n, k) << endl;
}
