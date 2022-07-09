#include<bits/stdc++.h>

using namespace std;
 #define ll long long


#define PB push_back
#define MP make_pair
typedef vector<int> vi;
typedef pair<int ,int> pi;
#define loop(i,a,n) for(int i=a;i<n;i++)
int firstindex(int a[],int x,int n,int k=0)
{
  if(k<0)
  {
    return-1;
  }
  if(a[k]==x)
  {
    return k;
  }
  else{
    return firstindex(a,x,n,k-1);
  }
  
}
 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
int *a=new int [n];
loop(i,0,n)
{
cin>>a[i];
}
int x;
cin>>x;
cout<<firstindex(a,x,n,n-1);
delete []a;

return 0;
}