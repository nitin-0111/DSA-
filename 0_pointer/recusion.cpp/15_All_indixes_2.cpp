#include<bits/stdc++.h>

using namespace std;
 #define ll long long


#define PB push_back
#define MP make_pair
typedef vector<int> vi;
typedef pair<int ,int> pi;
#define loop(i,a,n) for(int i=a;i<n;i++)


int allindex(int a[],int n,int x,int ( *output))
{
    if(n==0)
    {
        return 0;
    }
    int ans =allindex(a,n-1,x,output);
    if(a[n-1]==x)
    {
        output[ans]=n-1;
        ans++;
    }
    return ans;
   
   
} 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
int *a=new int [n];
int *output=new int [n];
loop(i,0,n)
{
    cin>>a[i];
}
int x;
cin>>x;
int ans=allindex(a,n,x,output);
cout<<ans<<endl;
loop(i,0,ans)
cout<<output[i]<<" ";
delete []output;

return 0;
}