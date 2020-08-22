#include <iostream>
#include<vector>
#include<limits.h>
using namespace std;

class maxHeap{
    vector<int> pq;
    int start , last;
public:
    bool isEmpty(){
        return pq.size()==0;
    }
    int getSize(){
        return pq.size();
    }
    int getMax(){
        if( isEmpty() ){
            return INT_MAX;  // represnts that queue is empty 
        }
        return pq[0];
    }
    void insert( int ele ){
        pq.push_back( ele );
        int child = pq.size()-1;
        int parent = (child-1)/2;
        
        //upheapify
        while( child > 0 && pq[parent] < pq[child] ){
            //swap
            int temp = pq[parent];
            pq[parent] = pq[child];
            pq[child] = temp;
            // changing child and parent again
            child = parent;
        	parent = (child-1)/2;
        }
    }
    int removeMax() {
        if( isEmpty() ){
            return INT_MAX;  // represnts that queue is empty 
        }
        int res = pq[0];
        int last = pq.size() - 1;
        pq[0] = pq[last];
        pq.pop_back();
        
        int parent = 0;
        int left = min ( 2*parent+ 1 , pq.size()-1 ); //make sure to check the limits here
        int right = min ( 2*parent+ 2 , pq.size()-1 );
    	int maxChild = ( pq[ left ] > pq[ right ] ) ? left : right ;
        //downheapify
        while( maxChild < pq.size()-1 && pq[parent] < pq[maxChild] ){
            //swap
            int temp = pq[parent];
            pq[parent] = pq[maxChild];
            pq[maxChild] = temp;
            
            parent = maxChild;
            left = min ( 2*parent+ 1 , pq.size()-1 );
        	right = min ( 2*parent+ 2 , pq.size()-1 );
    		maxChild = ( pq[ left ] > pq[ right ] ) ? left : right ;
        }
        return res;
    }
};
int main()
{
	int x=5;
    maxHeap h;
    for( int i = 0 ; i < 5 ; i++ ){
        h.insert(x);
        cout<< h.getMax() <<endl;
        x = (-1)*x*22;
    }
}