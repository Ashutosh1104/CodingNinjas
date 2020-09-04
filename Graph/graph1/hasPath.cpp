#include<iostream>
#include<stack>
using namespace std;

bool hasPath( int **a , bool *visited , int v , int start , int end){
    stack<int> s;
    s.push(start);
    visited[start] = 1;

    while( !s.empty() ){
        int curr = s.top();
        s.pop();
        if( curr == end ){
            return true;
        }

        for( int i = 0 ; i<v ; i++ ){
            if( i == curr ) continue;
            if( a[curr][i] && !visited[i] ){
                visited[i]=1;
                s.push(i);
            }
        }
    }
    return false;
}
int main(){
    int v , e ;
    cin>>v>>e;
    int **arr = new int*[v];
    for( int i = 0 ; i < v ; i++ ){
        arr[i] = new int[v];
        for( int j =0 ; j < v ; j++) arr[i][j]=0;
    }
    int x,y;
    for( int i =0 ; i<e ; i++ ){
        cin>>x>>y;
        arr[x][y]=1;
        arr[y][x]=1;
    }

    bool *visited = new bool[v];
    for( int i = 0 ; i<v;i++) visited[i]=0;

    int p1,p2;
    cin>>p1,p2;
    bool ans = hasPath(arr, visited , v , p1 , p2 );
    if( ans ) cout<<"true";
    else cout<<"false";
    return 0;
}