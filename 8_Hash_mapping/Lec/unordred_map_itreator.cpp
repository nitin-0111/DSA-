#include<bits/stdc++.h>

using namespace std;
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)


 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
unordered_map<string,int>mp;
mp["an"]=1;
mp["am"]=2;
for(auto x:mp)
{
    cout<<x.first<<" "<<x.second;
}
return 0;
}