#include <iostream>
#include <queue>
using namespace std;

void findMedian(int a[], int n){    
    priority_queue<int> maxh;
    priority_queue< int , vector<int> , greater<int> > minh;
    
    minh.push( a[0] );
    cout<<a[0]<<endl;
    for( int i = 1 ; i < n ; i++ ){  
        if(a[i] < minh.top() ){
            maxh.push( a[i] );
        }
        else minh.push(a[i]);

        while( (long long)(maxh.size() - minh.size()) > 1 || (long long)(minh.size() - maxh.size()) > 1 ){
            bool minLarger = minh.size() > maxh.size() ? true : false ;
            if( minLarger ){
                int temp = minh.top();
                maxh.push( temp );
                minh.pop();
            }
            else{
                int temp = maxh.top();
                minh.push( temp );
                maxh.pop();
            }
        }
        bool minLarger = minh.size() > maxh.size() ? true : false ;
        if( i % 2 == 0 ){
            if( minLarger ) cout << minh.top() << endl;
            else cout << maxh.top() << endl;
        }
        else{
            cout<< ( ( minh.top() + maxh.top() )/2 ) <<endl ;
        }
    }
}

int main() {
    
    int n;
    cin >> n;

    int arr[n], i;
    for(i=0;i<n;i++) cin >> arr[i];

    findMedian(arr, n);
}