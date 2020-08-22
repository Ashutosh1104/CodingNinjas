#include <iostream>
#include<vector>
#include<limits.h>
using namespace std;

class minHeap{
    vector<int> pq;
    int start , last;
public:
    bool isEmpty(){
        return pq.size()==0;
    }
    int getSize(){
        return pq.size();
    }
    int getMin(){
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
        while( child > 0 && pq[parent] > pq[child] ){
            //swap
            int temp = pq[parent];
            pq[parent] = pq[child];
            pq[child] = temp;
            // changing child and parent again
            child = parent;
        	parent = (child-1)/2;
        }
    }
    int removeMin() {
        if( isEmpty() ){
            return INT_MAX;  // represnts that queue is empty 
        }
        int res = pq[0];
        int last = pq.size() - 1;
        pq[0] = pq[last];
        pq.pop_back();
        
        int parent = 0;
        int left = min ( 2*parent+ 1 , pq.size() );   // make sure its at the borders 
        int right = min ( 2*parent+ 2 , pq.size() );
    	int minChild = ( pq[ left ] < pq[ right ] ) ? left : right ;
        //downheapify
        while( minChild < pq.size() && pq[parent] > pq[minChild] ){
            //swap
            int temp = pq[parent];
            pq[parent] = pq[minChild];
            pq[minChild] = temp;
            
            parent = minChild;
            left = min ( 2*parent+ 1 , pq.size() );
        	right = min ( 2*parent+ 2 , pq.size() );
    		minChild = ( pq[ left ] < pq[ right ] ) ? left : right ;
        }
        return res;
    }
};
int main()
{
	int x;
    minHeap h;
    for( int i = 0 ; i < 5 ; i++ ){
        cin>>x;
        h.insert(x);
        cout<< h.getMin() <<endl;
    }
}