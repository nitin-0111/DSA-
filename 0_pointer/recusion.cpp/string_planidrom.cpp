#include<bits/stdc++.h>

using namespace std;
 #define ll long long


#define PB push_back
#define MP make_pair
typedef vector<int> vi;
typedef pair<int ,int> pi;
#define loop(i,a,n) for(int i=a;i<n;i++)

bool planidriom(string s,int start,int end)
{
   
     if(start==end)return true;
    
   if(s[start]==s[end])
   {
    bool smallerpart=planidriom(s,start+1,end-1);
    return smallerpart;   
   }
   else return false;
   
   
   }
 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
string s;
cin>>s;
int l=s.length();
cout<<planidriom(s,0,l-1);

return 0;
}