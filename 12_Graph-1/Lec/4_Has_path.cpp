#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define loop(i, a, n) for (int i = a; i < n; i++)

bool Has_path(int **edges, int s, int e, bool *visited, int n)
{
    if (edges[s][e] == 1)
    {
        return true;
    }
    bool ans = false;
    for (int i = 0; i < n; i++)
    {
        if (s == i)
        {
            continue;
        }
        if (edges[s][i] == 1 && !visited[i])
        {
            visited[i]=true;
            ans = Has_path(edges, i, e, visited, n);
            if(edges[s][e]==1)
            {
                break;
            }
        }
        else
            continue;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int e;
    cin >> n >> e;
    int s,ev;
    cin>>s>>ev;
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
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    if(Has_path(edges,s,ev,visited,n))
    {
        cout<<"yes";
    }
    else
    cout<<"no";

    return 0;
}
/*INPUT: 

7  6
0 7
0 1
1 2
2 3
2 4
5 6
5 7

 
5 4
0 4
0 1
0 2
2 3
2 4
 


OUTPUT:

*/