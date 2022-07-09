// #include<bits/stdc++.h>

// using namespace std;
//  #define ll long long


// #define PB push_back
// #define MP make_pair
// typedef vector<int> vi;
// typedef pair<int ,int> pi;
// int cont( string s,int i)

// {
//      static int ct=0;

//     if(i==s.length())
//     {
//         return 0;
//     }
//     if(s[i]=='0')
//     {
//         ct++;
//     }
//  cont(s,i+1);
       
// return ct;

// }
 
// int main ()
// {
//   ios_base::sync_with_stdio(false);
// cin.tie(NULL);
// string s;
// cin>>s;
// cout<<cont(s,0);

// return 0;
// }
#include<bits/stdc++.h>

using namespace std;
 #define ll long long


#define PB push_back
#define MP make_pair
typedef vector<int> vi;
typedef pair<int ,int> pi;
 int cont(ll a)
{
  if(a==0)
  {
    return 1;
  }
  int digit=a%10;
   static int ct=0;
  if(digit==0)
  {
ct++;
  }
  cont(a/10);

  return ct;
}
 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll a;
cin>>a;
cout<<cont(a);
return 0;
}