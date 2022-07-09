#include<bits/stdc++.h>
#include"TREE-class.h"
using namespace std;
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)
int numcount(TreeNode<int>* root)
{
  if(root->children.size()==0)
  {
    return 0;
  }
    int ans=1;
    for(int i=0;i<root->children.size();i++)
    {
        ans+=numcount(root->children[i]);
    }
    return ans;
}


 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);

return 0;
}