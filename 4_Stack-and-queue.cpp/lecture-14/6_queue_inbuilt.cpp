#include<bits/stdc++.h>
#include<queue>
using namespace std;
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)


 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
queue<int>q;
q.push(10);
q.push(20);
q.push(30);
q.push(40);
q.push(50);
cout<<q.front()<<endl;
q.pop();
cout<<q.front()<<endl;
cout<<q.back()<<endl;
cout<<q.size()<<endl;
cout<<q.empty()<<endl;

return 0;
}