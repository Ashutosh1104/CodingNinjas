#include <iostream>
#include <stack>
#include <map>
using namespace std;

void PrintDFSpath(int **a, int *visited, int start, int end, int v)
{
    map<int, int> parentMap;
    stack<int> s;
    s.push(start);

    while (!s.empty())
    {
        int currEle = s.top();
        if (currEle == end)
            break;
        
        visited[currEle]=1;
        s.pop();

        for (int i = v - 1; i >= 0; i--) 
        {
            if (a[currEle][i] == 1 && !visited[i] && i != currEle)
            {
            	parentMap[i] = currEle;
                s.push(i);
            }
        }
    }
    if( s.empty() ) return;
    int i = end;
    cout<<end<<" ";
    while (i != start)
    {
        cout<<parentMap[i]<<" ";
        i = parentMap[i];
    }
}

int main()
{
    int v, e;
    cin >> v >> e;
    int **a = new int *[v];

    for (int i = 0; i < v; i++)
    {
        a[i] = new int[v];
        for (int j = 0; j < v; j++)
            a[i][j] = 0;
    }
    int x, y;
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }

    int v1, v2;
    cin >> v1 >> v2;

    int *visited = new int[v];
    for (int j = 0; j < v; j++)
        visited[j] = 0;

    PrintDFSpath(a, visited, v1, v2, v);
    return 0;
}