#include<bits/stdc++.h>

using namespace std;


 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)


int LootHouse(int *input,int n)
{
    if(n<=0)
    {
        return 0;
    }
    //
    int *ans=new int[n];
    for(int i=0;i<n;i++)
    {
        ans[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        int a=input[i]+LootHouse(input+2+i,n-2);
        int b=LootHouse(input+1,n-1);
        ans[i]=max(a,b);
    }
    int max=ans[0];
    for(int i=0;i<n;i++)
    {
        if(max<ans[i]){
            max=ans[i];
        }

    }
    return max;
} 

int LootHOuse_DP(int * input,int n)
{
    int * ans=new int [n];
    ans[0]=input[0];
    ans[1]=max(input[0],input[1]);
    for(int i=2;i<n;i++ )
    {
        ans[i]=max(input[i]+ans[i-2],ans[i-1]);
    }
    return ans[n-1];
}
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
int* INput=new int [n];
for(int i=0;i<n;i++)
{
    cin>>INput[i];
}
cout<<LootHOuse_DP(INput,n);

return 0;}
 /*INPUT: 



OUTPUT:

*/