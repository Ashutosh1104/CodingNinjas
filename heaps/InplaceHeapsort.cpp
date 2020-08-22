#include <iostream>
#include <algorithm>
using namespace std;
void inplaceHeapSort(int pq[], int n){
    for( int i = 1 ; i < n ; i++ ){
        int child = i;  
    	int parent = (child-1)/2;        

        while( child > 0 && pq[parent] > pq[child] ){
        	int temp = pq[parent];
        	pq[parent] = pq[child];
        	pq[child] = temp;

            child = parent;
        	parent = (child-1)/2;
    	}
    }
    int size =n;
    while( size>1){        
        int temp = pq[0];
    	pq[0] = pq[size-1];
    	pq[size-1] = temp;

        size -- ;
    	int parent = 0;
        int left = min ( 2*parent+ 1 , size );
        int right = min ( 2*parent+ 2 , size );
    	int minChild = ( pq[ left ] < pq[ right ] ) ? left : right ;

        while( minChild < size && pq[parent] > pq[minChild] ){
    		
       		int temp = pq[parent];
       		pq[parent] = pq[minChild];
       		pq[minChild] = temp;
            
       		parent = minChild;
            int left = min ( 2*parent+ 1 , size );
        	int right = min ( 2*parent+ 2 , size );
    		int minChild = ( pq[ left ] < pq[ right ] ) ? left : right ;
    	}
    }   
}
int main() {
	
	int size;
	cin >> size;
	int *input = new int[1 + size];
	
	for(int i = 0; i < size; i++)
		cin >> input[i];
	
	inplaceHeapSort(input, size);

	for(int i = 0; i < size; i++)
		cout << input[i] << " ";
	
	return 0;
}
