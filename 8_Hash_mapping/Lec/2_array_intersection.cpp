#include<bits/stdc++.h>

using namespace std;
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)


 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
int * a=new int [n];
unordered_map<int ,int>check;
for(int i=0;i<n;i++)
{
    cin>>a[i];
    check[a[i]]=1;
}
vector<int>intersection;
int m;
cin>>m;
int *b=new int [m];
for(int i=0;i<m;i++)
{
cin>>b[i];
if(check.count(b[i])>0)
{
    intersection.push_back(b[i]);
}

}
for(auto x:intersection)
{
    cout<<x<<" ";
}

delete []b;
delete []a;
return 0;
}