#include<bits/stdc++.h>

using namespace std;


 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)

void Get_path(int **edges,int s,int e,int n,bool *visited)
{
    if(edges[s][e]==1)
    {
        cout<<e;
        cout<<"<-"<<s;
        return ;
    }
    for(int i=0;i<n;i++)
    {
        if(i==s)
        {
            continue;
        }
        if(edges[s][i]==1&&!visited[i])
        {
            visited[i]=true;
            Get_path(edges,i,e,n,visited);
            if(s==0)
            {
                cout<<"<-"<<s;
            }
            break;
        }
        else
        continue;

    }
            // cout<<"<- "<<s;
}
 
int main ()
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
    Get_path(edges,s,ev,n,visited);
return 0;}
 /*INPUT: 



OUTPUT:

*/