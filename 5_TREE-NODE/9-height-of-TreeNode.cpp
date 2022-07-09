#include<bits/stdc++.h>
#include"1_TREE-class.h"
using namespace std;
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)
// int Height(TreeNode<int>* root,int ans=0)
// {
//   if(root->children.size()==0)
//   {
//     return 1;
//   }
   
//     int height=1;
//     for(int i=0;i<root->children.size();i++)
//     {
//         height+=Height(root->children[i],ans);
//         if(height>ans)
//         {
//           ans=height;
//           // asigning 1 to height for counting height from another route
//           height=1;
//         }
//     }
//     return ans;
// }
int Height(TreeNode<int> *root)
{
  if(root->children.size()==0)
  {
    return 0;
  }
  int h=1,hd=INT32_MIN;
  for(int i=0;i<root->children.size();i++)
  {
    hd=max(hd,Height(root->children[i]));
  }
  return h+hd;
}

//  1 3 2 3 4 1 5 0 0 2 6 7 0 0
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
TreeNode<int>*root =takeInputLevelwise();
cout<<Height(root);
return 0;
}