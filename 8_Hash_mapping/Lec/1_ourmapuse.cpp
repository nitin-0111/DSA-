#include<bits/stdc++.h>
#include"1_Ourmap.h"
using namespace std;
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)


 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
ourmap<int>map;
for(int i=0;i<15;i++)
{
    char c='0'+i+1;
    string key="abc";
    key+=c;
    int value=i+1;
    map.insert(key,value);
    cout<<map.getloadFactor()<<endl;
}
cout<<map.size()<<endl;
map.remove("abc2");
map.remove("abc7");
cout<<map.size()<<endl;
for(int i=0;i<15;i++)
{char c='0'+i;
    string key="abc";
    key+=c;
    cout<<key<<":"<<map.getvalue(key)<<endl;
    
}
cout<<map.size()<<endl;

return 0;
}