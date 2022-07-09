#include<bits/stdc++.h>

using namespace std;
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)


class stackUsingArray{
int *data;
int nextIndex;
public:
stackUsingArray(int totalsize)
{
    data=new int[totalsize];
    nextIndex=0;
}
//push()
void push(int n)
{
    data[nextIndex]=n;
    nextIndex++;
}
void pop(){
    nextIndex--;

}
void top(){
    cout<<data[nextIndex]<<" ";
}
void size()
{
    cout<<nextIndex<<" ";
}
bool isEmpty()
{
    if(nextIndex==0)
    {
        return true;
    }
    return false;
}
} ;
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);

return 0;
}