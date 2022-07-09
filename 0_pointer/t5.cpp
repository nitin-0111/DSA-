#include<bits/stdc++.h>

using namespace std;
 #define ll long long


#define PB push_back
#define MP make_pair
typedef vector<int> vi;
typedef pair<int ,int> pi;

float gm(int k)
{
    if(k==0)
    {
        return (1.0);
    }
    else
    {
        return pow(2,-k)+gm(k-1);
    }
    
} 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
int k;
cin>>k;
cout<<gm(k);
return 0;
}