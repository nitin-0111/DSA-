#include<bits/stdc++.h>

using namespace std;


 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)

int findMIN_vertex(int *distance,bool *visited,int n)
{
    int minVERTEX=-1;
    for(int i=0;i<n;i++){
        if(!visited[i]&&(minVERTEX==-1||distance[i]<distance[minVERTEX]))
        {
            minVERTEX=i;
        }
    }
    return minVERTEX;

}
/*   Dijkstra algorithem  similar ot prims*/
 void dijkstra(int **edges,int n)
 {
     int * distance=new int[n];// creating distance array;
     bool * visited=new bool [n];
     for(int i=0;i<n;i++)
     {
         distance[i]=INT_MAX;
         visited[i]=false;
     }
     distance[0]=0;// distance of source is marked 0 and other 's distance is infinate

     for(int i=0;i<n-1;i++) // no need for last one because it is only unvisited left and there is no need of calculation
    {
        int minVertex=findMIN_vertex(distance,visited,n);
        visited[minVertex]=true;
        for(int j=0;j<n;j++)
        {
            if(edges[minVertex][j]!=0&&!visited[j])// checking surrounding of minvertex which are not visited
            {
                int dist=distance[minVertex]+edges[minVertex][j];// calculating distance 
                if(dist<distance[j]){//                             and if there any short distace option then 
                    distance[j]=dist;//                       updating the distance;      
                }

            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<i<<" "<<distance[i]<<endl;

    }
    delete []visited;
    delete []distance;
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
        int f, s, weight;
        cin >> f >> s >> weight;
        edges[f][s] = weight;
        edges[s][f] = weight;
    }
    cout << endl;
    dijkstra(edges,n);
return 0;}
 /*INPUT: 

5 7 
0 1 4
0 2 8
1 3 5
1 2 2
2 3 5
2 4 9
3 4 4


OUTPUT:
 
0 0
1 4
2 6
3 9
4 13
 
*/