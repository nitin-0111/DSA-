#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define loop(i, a, n) for (int i = a; i < n; i++)

void printBFS(int **edges, int n, int sv)
{
    queue<int> pendingVertices;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    pendingVertices.push(sv);
    visited[sv] = true;
    while (!pendingVertices.empty())
    {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        cout << currentVertex << endl;
        for (int i = 0; i < n; i++)
        {
            if (i == currentVertex)
            {
                continue;
            }
            if (edges[currentVertex][i] == 1 && !visited[i])
            {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
    delete[] visited;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int e;
    cin >> n >> e;
    int **edge = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edge[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edge[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin>>f>>s;
        edge[f][s] = 1;
        edge[s][f] = 1;
    }
    cout<<"Print BFS"<<endl;
    printBFS(edge,n,0);

    return 0;
}
/*INPUT: 
1:
8
9
0 4
0 5
4 3
3 2
2 1
1 3
5 6
3 6
6 7

OUTPUT:
1:
0
4
5
3
6
1
2
7

*/