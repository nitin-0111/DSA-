#include<bits/stdc++.h>

using namespace std;
 #define ll long long


#define PB push_back
#define MP make_pair
typedef vector<int> vi;
typedef pair<int ,int> pi;
#define loop(i,a,n) for(int i=a;i<n;i++)


 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n,m;
cin>>n>>m;
int *a=new int [n],*b=new int [m];
loop(i,0,n)
cin>>a[i];
loop(i,0,m)
cin>>b[i];

sort(a,a+n);
sort(b,b+m);
loop(i,0,n)
cout<<a[i]<<" ";

cout<<endl;
loop(i,0,m)
cout<<b[i]<<" "<<endl;

cout<<endl;
int j=0,i=0;
while(i!=n)
{
    if(a[i]<b[j])
    {
        i++;
    }
    else if(b[j]<a[i])
    {
        j++;
    }
    else{
    cout<<a[i]<<" ";
    i++;
    j++;}
}

delete []a;
delete []b;

return 0;
}