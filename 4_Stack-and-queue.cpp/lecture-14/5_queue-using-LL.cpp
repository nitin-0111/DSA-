#include<bits/stdc++.h>

using namespace std;
#include "queue_using_LL.h"
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)


 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
QueueLL<int>q;
q.enqueue(10);
q.enqueue(20);
q.enqueue(30);
q.enqueue(40);
q.enqueue(50);

cout<<q.getsize()<<endl;
cout<<q.front()<<endl;
cout<<q.dequeue()<<endl;
cout<<q.dequeue()<<endl;
cout<<q.dequeue()<<endl;
cout<<q.dequeue()<<endl;
cout<<q.getsize()<<endl;
cout<<q.isEmpty()<<endl;
return 0;
}