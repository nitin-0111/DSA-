#include<bits/stdc++.h>

using namespace std;
#include"Trie.h"
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)


 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
Trie t;
t.insertWord("ans");
t.insertWord("and");
t.insertWord("an");
cout<<t.search("and")<<endl;
t.RemoveWord("and");
cout<<t.search("and")<<endl;
return 0;
}