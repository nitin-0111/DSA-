#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define loop(i, a, n) for (int i = a; i < n; i++)

void printBFS(int **edges, int n, int sv, bool *visited)
{
    queue<int> pendingVertices;

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
}
// for disconnected graph (also get printed)
void BFS(int **edges, int n)
{
    bool *visited = new bool[n]; // we are creating an array of non visited for call PrintBFS if
    for (int i = 0; i < n; i++)  //     // we are creating an array of non visited for call PrintBFS if t
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printBFS(edges, n, i, visited);
        }
    }
    delete[] visited;
}

// for disconnected graph (also get printed)
void printDFS(int **edges, int n, int sv, bool *visited) // we are creating an array of non visited for call PrintBFS if
{                                                        // we are creating an array of non visited for call PrintBFS if
    cout << sv << endl;
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edges[sv][i] == 1)
        {
            if (visited[i])
            {
                continue;
            }
            printDFS(edges, n, i, visited);
        }
    }
}

void DFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printDFS(edges, n, i, visited);
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
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    cout << "DFS :-" << endl;
    DFS(edges, n);
    cout << "BFS:-" << endl;
    BFS(edges, n);

    return 0;
}
/*INPUT: 
1:
7
5
0 2
0 3
2 3
1 4
5 6



OUTPUT:

*/