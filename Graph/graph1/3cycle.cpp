#include <iostream>
#include <vector>
#include <map>
using namespace std;

int count_cycle(vector<vector<int>> &graph, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> children;
        for (int x = 0; x < n; x++){
            if( graph[i][x] ){
                children.push_back(x);
            }
        }
        for (int x = 0; x < children.size(); x++){
            for (int y = 0; y < children.size() && x != y ; y++){
                if( graph[children[x]][children[y]] ){
                    count++;
                }
            }
        }
    }
    return count/3;
}

int solve(int n, int m, vector<int> u, vector<int> v)
{
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        graph[v[i] - 1][u[i] - 1] = 1;
        graph[u[i] - 1][v[i] - 1] = 1;
    }

    return count_cycle(graph, n);
}
int main()
{
    int n, m;
    vector<int> u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        u.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << solve(n, m, u, v) << endl;
}