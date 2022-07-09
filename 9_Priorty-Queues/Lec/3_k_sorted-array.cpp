#include<bits/stdc++.h>

using namespace std;
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)


void KSortedArray(int input[],int n,int k)          // total   O(n*log(k))
{
    priority_queue<int> p;
    for(int i=0;i<k;i++)
    {
        p.push(input[i]);   //O(k* log(k))
    }
    int j=0;
    for(int i=k;i<n;i++)
    {
        input[j]=p.top();       //O((n-k)*logk)
        p.pop();
        p.push(input[i]);   //O(k* log(k))
        j++;
    }
    while(!p.empty())
    {
        input[j]=p.top();
        p.pop();
        j++;
    }
} 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
int input[]={10,12,6,7,9,0,5,8};
int k=5;
KSortedArray(input,8,k);
for(int x: input)
{
    cout<<x<<" ";
}
cout<<endl;
return 0;
}