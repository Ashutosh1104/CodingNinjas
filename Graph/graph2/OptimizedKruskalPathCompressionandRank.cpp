#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// UF by rank and Path compression
const int MAX_VERTEX = 101; 
int parent[MAX_VERTEX]; 
int size[MAX_VERTEX]; // could not name rank as name exists in #include <algorithm> and along with namespace it conflicts

void initialize(int n)  // Makeset 
{ 
    for (int i = 0; i <= n; i++) { 
        parent[i] = i; 
        size[i] = 1; 
    } 
} 
int find_parent(int p)
{
    while (parent[p] != p)
    {
        parent[p] = parent[parent[p]];
        p = parent[p];
    }
    return (parent[p]);
}
void Union(int p, int q)
{
    int proot = find_parent(p);
    int qroot = find_parent(q);
    if (size[proot] < size[qroot])
    {
        parent[proot] = qroot;
        size[qroot] = size[proot] + size[qroot];
    }
    else
    {
        parent[qroot] = proot;
        size[proot] = size[qroot] + size[proot];
    }
}

// Kruskals starts here
struct edges
{
    int source, destination, weight;
};
bool compare(edges e1, edges e2)
{
    return e1.weight < e2.weight;
}
int main()
{
    int n, e;
    cin >> n >> e;

    edges input[e], output[n - 1];
    initialize(n);

    for (int i = 0; i < e; i++)
        cin >> input[i].source >> input[i].destination >> input[i].weight;

    sort(input, input + e, compare);

    int count = 0, i = 0, v1, v2;
    while (count < n - 1)
    {
        v1 = input[i].source;
        v2 = input[i].destination;
        int pv1 = find_parent(v1); // find
        int pv2 = find_parent(v2); // find
        if (pv1 != pv2)
        { 
            Union(v1,v2);
            output[count].source = input[i].source;
            output[count].destination = input[i].destination;
            output[count].weight = input[i].weight;
            count++;
        }
        i++;
    }

    for (int i = 0; i < n - 1; i++)
    {
        int minVertex = min(output[i].source, output[i].destination);
        int maxVertex = max(output[i].source, output[i].destination);
        cout << minVertex << " " << maxVertex << " " << output[i].weight << endl;
    }
    return 0;
}