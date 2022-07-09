#include<bits/stdc++.h>

using namespace std;
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)


 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
priority_queue<int>p;
p.push(123);//inbuilt is max priority queue 
p.push(923);
p.push(23);
p.push(13);
p.push(12);
cout<<" size : "<<p.size()<<endl;
cout<<" top : "<<p.top()<<endl;
while(!p.empty())
{
    cout<<p.top()<<" ";
    p.pop();
}
cout<<endl;

return 0;
}