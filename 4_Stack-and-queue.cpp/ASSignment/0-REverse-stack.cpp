#include<bits/stdc++.h>

using namespace std;
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)
// 000
void reverse_stack(stack<int> &s)
{
    if(s.size()==0)
    {
        return ;
    }
    stack<int>R;
    int x=s.top();
    s.pop();
    reverse_stack(s);
    while(s.size()!=0)
    {
        R.push(s.top());
        s.pop();


    }
    s.push(x);
    while(R.size()!=0)
    {
        s.push(R.top());
        R.pop();
    }
}
void print_stack(stack<int> s)
{
    while(s.size()!=0)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
stack<int>s;
int n;
cin>>n;
while(n--)
{
    int x;
    cin>>x;
    s.push(x);
}
cout<<s.top()<<endl;
reverse_stack(s);
cout<<s.top()<<endl;
print_stack(s);

return 0;
}