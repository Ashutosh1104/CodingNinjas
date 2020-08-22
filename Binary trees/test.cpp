#include <iostream>
using namespace std;
void insert( int* pq , int heapBorder ){ // as it in inplace send the array itself as a input 
    //pq.push_back( ele );// instead of size we got a border and we need to use it as last element and dont need to pushback cuz its already 								there we just need to heapify
    int child = heapBorder;  
    int parent = (child-1)/2;        
    //upheapify
    while( child > 0 && pq[parent] > pq[child] ){
        int temp = pq[parent];
        pq[parent] = pq[child];
        pq[child] = temp;
            // changing child and parent again
        child = parent;
        parent = (child-1)/2;
    }
}
void removeMin( int* pq , int heapBorder ) { // no need to delete and return as we are not removing anything we are just swapping and reheapifying
    int temp = pq[0];
    pq[0] = pq[heapBorder];
    pq[heapBorder] = temp;
       
    int parent = 0;
    int minChild = ( pq[ 2*parent+ 1 ] < pq[ 2*parent + 2 ] ) ? 2*parent+ 1 : 2*parent+ 2 ;
    //downheapify
    while( minChild < heapBorder && pq[parent] > pq[minChild] ){
    
       int temp = pq[parent];
       pq[parent] = pq[minChild];
       pq[minChild] = temp;
            
       parent = minChild;
       minChild = ( pq[ 2*parent+ 1 ] < pq[ 2*parent + 2 ] ) ? 2*parent+ 1 : 2*parent+ 2 ;
    }
}
void inplaceHeapSort(int input[], int n){
    for( int i = 1 ; i < n ; i++ ){
        insert( input , i );
    }
    for(int i = n-1; i > 1; i--){
		removeMin( input , i );
    }
}

int main() {
	
	int size;
	cin >> size;
	int input[1 + size];
	
	for(int i = 0; i < size; i++)
		cin >> input[i];
	
	inplaceHeapSort(input, size);

	for(int i = 0; i < size; i++)
		cout << input[i] << " ";	
	return 0;
}


