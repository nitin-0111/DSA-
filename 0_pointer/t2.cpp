#include<bits/stdc++.h>

using namespace std;
 #define ll long long


#define PB push_back
#define MP make_pair
typedef vector<int> vi;
typedef pair<int ,int> pi;
int muti(int m,int n)
{ 
    int ans;

    if(n==0)
    {
        return 0;
    }
    else 
    {
       ans=m+muti(m,n-1);
      

    }
    return ans;
}
 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
int m,n;
cin>>m>>n;
int ans=m>n?muti(m,n):muti(n,m);
cout<<ans;
return 0;
}