#include<bits/stdc++.h>

using namespace std;
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)


void k_largest_number(int a[],int n,int k)
{
    priority_queue<int,vector<int>,greater<int>>p;
    for(int i=0;i<k;i++)
    {
        p.push(a[i]);

    }
    for(int i=k;i<n;i++)
    {
        if(p.top()<=a[i])
        {
            p.pop();
            p.push(a[i]);
        }
    }
    for(int i=0;i<k;i++)
    
    {
        cout<<p.top()<<endl;
        p.pop();
    }

} 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
int k;
int *a=new int[n];
for(int i=0;i<n;i++)
{
    cin>>a[i];
}
cin>>k;
k_largest_number(a,n,k);
return 0;
}