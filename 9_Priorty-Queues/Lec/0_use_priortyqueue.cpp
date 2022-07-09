#include<bits/stdc++.h>

#include"PriortyQueue.h"
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)


 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
PriortyQueue s;
s.insert_min(10);
s.insert_min(20);
s.insert_min(30);
s.insert_min(50);
s.insert_min(70);
s.insert_min(60);
s.insert_min(40);
s.insert_min(80);
s.print();
cout<<s.getsize()<<endl;
cout<<s.getMin()<<endl;
cout<<s.removeMin()<<endl;
s.print();
cout<<s.removeMin()<<endl;
s.print();
cout<<s.removeMin()<<endl;
s.print();
cout<<s.getsize()<<endl;
cout<<s.getMin()<<endl;
s.print();

// PriortyQueue s;
// s.insert_max(10);
// s.insert_max(20);
// s.insert_max(30);
// s.insert_max(50);
// s.insert_max(70);
// s.insert_max(60);
// s.insert_max(40);
// s.insert_max(80);
// s.print();
// cout<<s.getsize()<<endl;
// cout<<s.getmax()<<endl;
// cout<<s.removeMax()<<endl;
// s.print();
// cout<<s.removeMax()<<endl;
// s.print();
// cout<<s.removeMax()<<endl;
// s.print();
// cout<<s.getsize()<<endl;
// cout<<s.getmax()<<endl;
// s.print();

return 0;
}