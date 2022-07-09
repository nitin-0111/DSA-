#include<bits/stdc++.h>

using namespace std;
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)


 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
string s;
cin>>s;
int * a=new int [256];
for(int i=0;i<s.length();i++)
{
    a[(s[i])]=1;
}
for(int i=0;i<256;i++)
{
    if(a[i]==1)
    {
        char d=i;
        cout<<d;
    }
}

delete []a;

return 0;
}