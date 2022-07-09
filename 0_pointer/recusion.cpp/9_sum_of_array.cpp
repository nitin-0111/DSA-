#include<bits/stdc++.h>

using namespace std;
 #define ll long long


#define PB push_back
#define MP make_pair
typedef vector<int> vi;
typedef pair<int ,int> pi;
#define loop(i,a,n) for(int i=a;i<n;i++)
int sum(int a[],int n)
{
    if(n==1)
    {
        return a[0];
    }
    int next=sum(a+1,n-1);
    return a[0]+next;
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
cout<<sum(a,n);
delete []a;
return 0;
}