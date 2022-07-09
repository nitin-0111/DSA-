#include<bits/stdc++.h>

using namespace std;
 #define ll long long


#define PB push_back
#define MP make_pair
typedef vector<int> vi;
typedef pair<int ,int> pi;
#define loop(i,a,n) for(int i=a;i<n;i++)

void replace(string s,int n,char a,char x)
{
    if(n==0)
    {
        return;
    }
    if(s[0]!='a')
    {
        replace(s,n-1,a,x)
    }
}
 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
string s;
cin>>s;

return 0;
}