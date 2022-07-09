#include<bits/stdc++.h>

using namespace std;


 #define ll long long
#define MOD 1000000007
//  it is like DFS bcz we
void print(int **edges,int n,int sv,int *visited)
{
    cout<<sv<<endl;
    visited[sv]=true;
    for(int i=0;i<n;i++)
{
     if(i==sv)
     {
         continue;

     }
     if(edges[sv][i]==1)
     {
         if(visited[i])
         {
             continue;
         }
         print(edges,n,i,visited);
     }
}
}
 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
int e;
cin>>n>>e;
int **edges=new int *[n];

for(int i=0;i<n;i++)
{
    edges[i]=new int [n];
    for(int j=0;j<n;j++)
    {
        edges[i][j]=0;
    }
}
bool  *visited=new bool[n];
for(int i=0;i<n;i++)
{
    visited[i]=false;
}
print(edges,n,0,visited);
return 0;}
 /*INPUT: 



OUTPUT:

*/
