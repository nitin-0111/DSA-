#include<bits/stdc++.h>
#include"TREE-class.h"
using namespace std;
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)


 bool contain_x(int x, TreeNode<int>*root)
 {
     if(root==NULL)
     {
         return 0;
     }
     if(root->data==x)
     {
         return true;
     }
     bool ans;
     for(int i=0;i<root->children.size();i++)
     {
         ans=contain_x(x,root->children[i]);

     }
     return ans;
 }
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
int x;
cin>>x;
TreeNode<int>* root=takeInputLevelwise();
cout<<contain_x(x,root);

return 0;
}