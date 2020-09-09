#include <iostream>
#include <vector>
using namespace std;
#define NMAX 55
int visited[NMAX][NMAX];
int a[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

bool check_valid(int x, int y, int n)
{
    if (x >= 0 && y >= 0 && x < n && y < n)
        return true;
    return false;
}

int sizedfs(int n, char cake[NMAX][NMAX], int i, int j)
{
    if(visited[i][j]) return 0;

    visited[i][j] = 1;
    int size = 1;
    for (int var = 0; var < 4; var++)
    {
        int x = i + a[var][0];
        int y = j + a[var][1];

        if (check_valid(x, y, n) && cake[x][y] == '1')
        {
            size += sizedfs(n, cake, x, y);
        }
    }
    return size;
}

int solve(int n, char cake[NMAX][NMAX])
{
    int maxSize = 0, currSize = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cake[i][j] == '1' && !visited[i][j] )
            {
                currSize = sizedfs(n, cake, i, j);
                maxSize = max(maxSize, currSize);
            }
        }
    }
    return maxSize;
}

char cake[NMAX][NMAX];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", cake[i]);
    }
    cout << solve(n, cake) << endl;
    return 0;
}