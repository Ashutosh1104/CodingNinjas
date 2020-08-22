#include<iostream>
#include<algorithm>
using namespace std;
bool checkMaxHeap(int a[], int n){
    int parent = 0;    
    while( parent < n ){
        int left = min ( 2*parent +1 , n );
    	int right = min ( 2*parent +2 , n );
        if( a[parent] < a[left] || a[parent] < a[right] ) return false;
        parent++;
    }
    return true;
}

int main() {
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    bool ans = checkMaxHeap(arr, n);
    if(ans){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    
    delete [] arr;
}
