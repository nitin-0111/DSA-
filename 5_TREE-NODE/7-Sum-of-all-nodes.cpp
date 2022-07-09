#include<bits/stdc++.h>
#include"TREE-class.h"
using namespace std;
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)

int sumofallnode(TreeNode<int>* root)
{
    int ans=root->data;
    for(int i=0;i<root->children.size();i++)
    {
        ans+=sumofallnode(root->children[i]);
    }
    return ans;
}

 int LargestTreeNode(TreeNode<int>* root)
 {
   int max=root->data;
   for(int i=0;i<root->children.size();i++)
   {
     int a=LargestTreeNode(root->children[i]);
     if(a>max)
     {
       max=a;
     }

   }
   return max;
 }
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
TreeNode<int>* root=takeInputLevelwise();
cout<<LargestTreeNode(root);
return 0;
}