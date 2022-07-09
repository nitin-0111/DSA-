#include<bits/stdc++.h>

using namespace std;
 #define ll long long


#define PB push_back
#define MP make_pair
typedef vector<int> vi;
typedef pair<int ,int> pi;

bool is_sorted(int a[],int size)
{
  if(size==0||size==1)
  {
    return true;
  }
  bool smaller_part=is_sorted(a+1,size-1);
  
  if(a[0]>a[1])
  {
    return false;
  }
  return smaller_part;
} 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
int a[]={1,2,3,4,0};
int size=sizeof(a)/sizeof(a[0]);
cout<<is_sorted(a,size);
return 0;
}