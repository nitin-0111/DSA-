#include<bits/stdc++.h>

using namespace std;
 #define ll long long


#define PB push_back
#define MP make_pair
typedef vector<int> vi;
typedef pair<int ,int> pi;
#define loop(i,a,n) for(int i=a;i<n;i++)


 /* two pointer's method*/
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
int m;
cin>>m;
int *a=new int [m];
int x;

loop(i,0,m)
cin>>a[i];

sort(a,a+m);
cin>>x;
int i=0,j=m-1;
while(i<=j)
{
int sum=a[i]+a[j];
if(x<sum){
    j--;
}
else if(x>sum)
{
    i++;
}
else {
    cout<<a[i]<<" "<<a[j];
    i++;
    j--;
}
}
return 0;
}