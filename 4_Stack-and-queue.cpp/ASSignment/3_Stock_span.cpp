#include<bits/stdc++.h>

using namespace std;
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)


 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
int *a=new int[n];
for(int i=0;i<n;i++)
{
    cin>>a[i];
}
int * ans=new int [n];
ans[0]=1;
stack<int>s;
s.push(0);
for(int i=1;i<n;i++)
{
    if(a[s.top()]>=a[i])
    {
        s.push(i);
        ans[i]=i-s.top()+1;

    }
    else{
        while(!s.empty()||a[s.top()]>a[i])
        {
            s.pop();
        }
            ans[i]=i-s.top()+1;
    }
}
for(int i=0;i<n;i++)
{
    cout<<ans[i]<<" ";
}
return 0;
}
// #include<bits/stdc++.h>

// using namespace std;
//  #define ll long long
// #define loop(i,a,n) for(int i=a;i<n;i++)

// void stock_span(int*& a,int j )
// {
//     if(j<0)
//     {
//         return ;
//     }
    
//     int i=j-1;
//     int ct=1;
//     while(a[i]<a[j])
//     {
//         ct++;

//     }
//     a[j]=ct;
//     ct=0;
//     stock_span(a,j-1);
    

// }
 
// int main ()
// {
//   ios_base::sync_with_stdio(false);
// cin.tie(NULL);
// int n;
// cin>>n;
// int *a=new int [n];
// for(int i=0;i<n;i++)
// {
//     cin>>a[i];

// }
// stock_span(a,n-1);
// for(int i=0;i<n;i++)
// {
//     cout<<a[i]<<" ";

// }
// cout<<endl;

// return 0;
// }
// #include<bits/stdc++.h>

// using namespace std;
//  #define ll long long
// #define loop(i,a,n) for(int i=a;i<n;i++)



// void reverse_stack(stack<int> &s)
// {
//     if(s.size()==0)
//     {
//         return ;
//     }
//     stack<int>R;
//     int x=s.top();
//     s.pop();
//     reverse_stack(s);
//     while(s.size()!=0)
//     {
//         R.push(s.top());
//         s.pop();


//     }
//     s.push(x);
//     while(R.size()!=0)
//     {
//         s.push(R.top());
//         R.pop();
//     }
// }


// stack<int> stock_span(stack<int>a)
// {
//     if(a.empty())
//     {
//         return a;
//     }
//     stack<int> temp(a);
//     static stack<int> ans;
//     int ct=1;
//     int x=a.top();
//     a.pop();
//     while(temp.top()<x)
//     {
//         ct++;
//         temp.pop();
//     }
//     ans.push(ct);
//     ct=0;
//     stack<int>smaller=stock_span(a);
//     reverse_stack(smaller);
//     while(!smaller.empty())
//     {
//         int x=smaller.top();
//         smaller.pop();
//         ans.push(x);
        
//     }

// return ans;
// }
 
 


// void print_stack(stack<int> s)
// {
//     while(s.size()!=0)
//     {
//         cout<<s.top()<<" ";
//         s.pop();
//     }
//     cout<<endl;
// }

// int main ()
// {
//   ios_base::sync_with_stdio(false);
// cin.tie(NULL);
// stack<int> s;
// int n;
// cin>>n;
// while(n--)
// {
//     int x;
//     cin>>x;
//     s.push(x);
// }

// // stack<int> a=s;
// //print_stack(a);
// //print_stack(s);
// stack<int>temp=stock_span(s);
// print_stack(temp);

// return 0;
// }