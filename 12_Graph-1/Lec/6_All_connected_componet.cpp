#include<bits/stdc++.h>

using namespace std;


 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)

void smallpart(int **edges,int n,int sv,bool* visited,vector<int>& temp)
{
    for(int i=0;i<n;i++)
    {
        if(i==sv)
        {
            continue;
        }
        if(edges[sv][i]==1&&!visited[i])
        {
            visited[i]=true;
            temp.push_back(i);
            smallpart(edges,n,i,visited,temp);
        }
    }
}

vector<vector<int>> ALLconnectedComp(int **edges,int n)
{
    vector<vector<int>> finalans;
    bool*visited=new bool [n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            vector<int>temp;
            visited[i]=true;
            temp.push_back(i);
            smallpart(edges,n,i,visited,temp);
            finalans.push_back(temp);
        }
    }
    return finalans;
}
 
int main ()
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
    vector<vector<int>> ans=ALLconnectedComp(edges,n);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
return 0;}
 /*INPUT: 



OUTPUT:

*/