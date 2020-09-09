#include <bits/stdc++.h>
using namespace std;
#define MAXN 102
int visited[MAXN][MAXN];

void nextIndex(char Graph[][MAXN],int i, int j, char next, vector<pair<int, int>> &p, int M, int N)
{
    int x, y;
    x = i - 1, y = j - 1;
    if (x >= 0 && j >= 0 && x < N && y < M)
    {
        if (Graph[x][y] == next && !visited[x][y])
        {
            p.push_back({x, y});
        }
    }
    x = i - 1, y = j;
    if (x >= 0 && j >= 0 && x < N && y < M)
    {
        if (Graph[x][y] == next && !visited[x][y])
        {
            p.push_back({x, y});
        }
    }
    x = i - 1, y = j + 1;
    if (x >= 0 && j >= 0 && x < N && y < M)
    {
        if (Graph[x][y] == next && !visited[x][y])
        {
            p.push_back({x, y});
        }
    }
    x = i, y = j - 1;
    if (x >= 0 && j >= 0 && x < N && y < M)
    {
        if (Graph[x][y] == next && !visited[x][y])
        {
            p.push_back({x, y});
        }
    }
    x = i, y = j + 1;
    if (x >= 0 && j >= 0 && x < N && y < M)
    {
        if (Graph[x][y] == next && !visited[x][y])
        {
            p.push_back({x, y});
        }
    }
    x = i + 1, y = j - 1;
    if (x >= 0 && j >= 0 && x < N && y < M)
    {
        if (Graph[x][y] == next && !visited[x][y])
        {
            p.push_back({x, y});
        }
    }
    x = i + 1, y = j;
    if (x >= 0 && j >= 0 && x < N && y < M)
    {
        if (Graph[x][y] == next && !visited[x][y])
        {
            p.push_back({x, y});
        }
    }
    x = i + 1, y = j + 1;
    if (x >= 0 && j >= 0 && x < N && y < M)
    {
        if (Graph[x][y] == next && !visited[x][y])
        {
            p.push_back({x, y});
        }
    }
}
int findPath(char Graph[][MAXN], int var, int i, int j, int M, int N)
{
    if( var >= 10 ) return 1;
    string s = "CODINGNINJA";
    visited[i][j] = 1 ;
    char next = s[var + 1];
    vector<pair<int, int>> p;
    nextIndex(Graph, i, j, next, p, M, N);

    int found = 0;

    for( auto nextInd : p ){
        int x = nextInd.first;
        int y = nextInd.second;
        if( !visited[x][y] ){
            found = found | findPath(Graph,var+1,x,y,M,N);
        }
    }
    visited[i][j] = 0;
    return found;
}
int solve(char Graph[][MAXN], int N, int M)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (Graph[i][j] == 'C')
            {
                if (findPath(Graph, 0, i, j, M, N))
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    int N, M, i;
    char Graph[MAXN][MAXN];
    cin >> N >> M;
    for (i = 0; i < N; i++)
    {
        cin >> Graph[i];
    }
    cout << solve(Graph, N, M) << endl;
}