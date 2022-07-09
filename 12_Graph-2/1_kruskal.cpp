#include<bits/stdc++.h>

using namespace std;


 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)

class edge{
    public:
    int source;
    int des;
    int weight;

};
bool compareWeight(edge a,edge b)
{
    return (a.weight<b.weight);
}

int parent_fun(int v1,int *parent)
{
    if(parent[v1]==v1)
    {
        return v1;

    }
    return parent_fun(parent[v1],parent);
}
 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n,e;
cin>>n>>e;
edge * input=new edge[e];
for(int i=0;i<e;i++)
{
    int s,d,w;
    cin>>s>>d>>w;
    input[i].source=s;
    input[i].des=d;
    input[i].weight=w;
}
sort(input,input+e,compareWeight);
edge* output=new edge[n-1];
// int *check=new int [n];
int *parent=new int[n];
for(int i=0;i<n;i++)
{
    // check[i]=-1;
    parent[i]=i;
}
int i=0,count=0;
while(count!=n-1)
{
    int v1=input[i].source;
    int v2=input[i].des;

    int pv1=parent_fun(v1,parent);
    int pv2=parent_fun(v2,parent);
    if(pv1!=pv2)
    {
        output[count]=input[i];
        count++;
        parent[pv1]=pv2;
    }
    i++;
}
cout<<endl;
for(int i=0;i<n-1;i++)
{
    if(output[i].source<output[i].des)
  
 cout<<output[i].source<<" "<<output[i].des<<" "<<output[i].weight<<endl;
else
 cout<<output[i].des<<" "<<output[i].source<<" "<<output[i].weight<<endl;

}


return 0;}
 /*INPUT: 
6 11
0 1 1
0 2 5
2 3 10
0 3 4
1 3 3
1 2 6
3 4 7
2 4 8
4 5 2
2 5 9
3 5 6



6 11
0 1 2
1 3 1
0 2 4
2 4 9
4 5 5
3 5 7
4 3 11
2 5 10
0 3 3
2 1 8
2 3 6



OUTPUT:

*/