#include<bits/stdc++.h>

using namespace std;
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)

void reverse_queue(queue<int>& q)
{
    if(q.size()==0)
    {
        return;
    }
    int x=q.front();
    q.pop();
    reverse_queue(q);
    q.push(x);
}
void print_queue(queue<int>q)
{
    while(q.size()!=0)
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}
 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
queue<int>q;
int n;
cin>>n;
while(n--)
{
int x;
cin>>x;
q.push(x);

}
print_queue(q);
cout<<q.front()<<endl;
reverse_queue(q);
print_queue(q);
cout<<q.front()<<endl;


return 0;
}