#include<bits/stdc++.h>

using namespace std;
 #define ll long long


#define PB push_back
#define MP make_pair
typedef vector<int> vi;
typedef pair<int ,int> pi;
#define loop(i,a,n) for(int i=a;i<n;i++)

void removex(char s[])
{
    if(s[0]=='\0')
    {
        return;
    }
    if(s[0]!='x')
    {
        removex(s+1);
    }
    else
    {
        int i=1;
        for(;s[i]!='\0';i++)
        {
            s[i-1]=s[i];
        }
        s[i-1]=s[i];
        removex(s);
    }
}
 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
char s[100];
cin>>s;
removex(s);
cout<<s;
return 0;
}