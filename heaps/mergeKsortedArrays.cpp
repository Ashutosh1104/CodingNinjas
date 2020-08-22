#include <iostream>
#include <vector>
#include <queue>
#include<utility>
using namespace std;

typedef pair<int, pair<int, int> > object;   // first= value  // second.first = from which array // second.second = index in that array 

vector<int> mergeKSortedArrays( vector<vector<int>*> a ){
    priority_queue< object , vector< object > , greater<object>  > pq;
    vector<int> res;
    int k = a.size();
    for( int i=0 ; i < k ; i++ ){
        if( a[i]->size() > 0 ){   // if the array is emoty we do not want to push garbage
            pq.push({ a[i]->at(0) , { i, 0 } });
        }
    }
    int i = 0;
    while( !pq.empty() ){
        res.push_back( pq.top().first );
        
        auto x = pq.top();
        pq.pop();
        
        int arrayNo = x.second.first;
        int index = x.second.second;
        
        if( index+1 < a[ arrayNo ]->size() ){
            pq.push( { a[arrayNo]->at(index+1) , { arrayNo , index+1 } } );
        }
    }    
    return res;
}

int main() {
	
	int k;
	cin >> k;
    vector<vector<int>*> input;
    for(int j = 1; j <= k; j++) {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;
        
        for(int i = 0; i < size; i++) {
            int a;
            cin >> a;
            current -> push_back(a);
        }
        input.push_back(current);
    }
	
	
	vector<int> output = mergeKSortedArrays(input);

	for(int i = 0; i < output.size(); i++)
		cout << output[i] << " ";
	
	return 0;
}
