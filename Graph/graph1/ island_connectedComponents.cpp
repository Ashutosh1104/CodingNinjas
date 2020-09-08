#include<iostream>
#include<vector>
using namespace std;
void dfs( int** a , bool *visited , int start , int v ){
    visited[start] = true;
    for( int i =0 ; i<v ; i++){
        if( i != start && a[start][i]==1 && !visited[i]){
            dfs(a,visited,i,v);
        }
    }
}
int solve(int n,int m,vector<int>u,vector<int>v)
{
	int **a = new int*[n];
    for( int i =0 ; i< n ;i++){
        a[i] = new int[n];
        for( int j =0 ; j<n;j++){
            a[i][j]=0;
        }
    }
    for( int i =0 ; i<m;i++){
        a[u[i]-1][v[i]-1] = 1 ;
        a[v[i]-1][u[i]-1] = 1 ;
    }

    bool visited[n];
    for( int i =0 ; i< n ;i++){
        visited[i]=0;
    }
    int count=0;
    for( int i =0 ; i< n ;i++){
        if( !visited[i] ){
            count++;
            dfs(a,visited,i,n);
        }
    }
    return count;
}
int main()
{
	int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		u.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<solve(n,m,u,v)<<endl;
}