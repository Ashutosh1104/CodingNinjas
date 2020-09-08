#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

// DFS printing root == vertex we are starting from
void DFSrecursive(int **edges, int root, int *visited, int n)
{
    cout << root << endl;
    visited[root] = 1;
    for (int i = 0; i < n; i++)
    {
        // a[root][root] doesn't makes sense
        if (i == root)
            continue;
        if (edges[root][i] && !visited[i])
        {
            DFSrecursive(edges, i, visited, n);
        }
    }
}

// Read this : https://stackoverflow.com/questions/12864004/tracing-and-returning-a-path-in-depth-first-search
void DFSIteratve(int **a, int *visited, int start, int v)
{
    stack<int> s;
    s.push(start);

    while (!s.empty())
    {
        int currEle = s.top();
        if( !visited[currEle] ){
            cout<<currEle<<" ";
        }

        visited[currEle]=1;
        s.pop();

        for (int i = v - 1; i >= 0; i--) 
        {
            if (a[currEle][i] == 1 && !visited[i] && i != currEle)
                s.push(i);
        }
    }
}

void DFS(int **arr, int v)
{
    int *visited = new int[v];
    for (int i = 0; i < v; i++)
        visited[i] = 0;

    // this looping is done to accomodate graphs which are disconnected for fully connected grah it is not needed
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            DFSrecursive(arr, i, visited, v);
        }
    }
}
int main()
{
    // ask user for no of vertices and edges
    int v, e;
    cin >> v >> e;

    // intialize a 2d matrix with all values 0
    int **a = new int *[v];
    for (int i = 0; i < v; i++)
    {
        a[i] = new int[v];
        memset(a[i], 0, v);
    }
    // get edges from user and set the values to 1 where edge exists
    int x, y;
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y;
        // add edge on both an it is undirected graph
        a[x][y] = 1;
        a[y][x] = 1;
    }

    // visited keeps tracks of all vertices we have gone over
    int *visited = new int[v];
    for (int i = 0; i < v; i++)
        visited[i] = 0;
    DFS(a, v);
}