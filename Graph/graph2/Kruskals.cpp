#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edges
{
    int source, destination, weight;
};
bool compare(edges e1, edges e2)
{
    return e1.weight < e2.weight;
}

int find_parent( int v1 , int * parent){
    int pv1 = v1;
    while( parent[pv1] != pv1 ){
        pv1 = parent[pv1];
    }    
    return pv1;
}

// void kruskal( int* input , int* parent , int count , int n , int e ){

// }

int main()
{
    int n, e;
    cin >> n >> e;

    edges input[e], output[n - 1];
    int parent[n];
    for(int i = 0; i < n; i++) parent[i]=i;

    for (int i = 0; i < e; i++)
        cin >> input[i].source >> input[i].destination >> input[i].weight;

    sort(input, input + e, compare);

    int count = 0 , i = 0 , v1 , v2 ;
    while( count < n-1){
        v1 = input[i].source ; 
        v2 = input[i].destination;
        int pv1 = find_parent(v1,parent); // find
        int pv2 = find_parent(v2,parent); // find
        if( pv1 != pv2 ){ // union
            parent[pv2] = pv1;
            output[count].source = input[i].source;
            output[count].destination = input[i].destination;
            output[count].weight = input[i].weight;
            count++;
        }
        i++;
    }

    for( int i = 0 ; i < n-1 ;i++){
        int minVertex = min( output[i].source , output[i].destination );
        int maxVertex = max( output[i].source , output[i].destination );
        cout<<minVertex<<" "<<maxVertex<<" "<<output[i].weight<<endl;
    }
    return 0;
}