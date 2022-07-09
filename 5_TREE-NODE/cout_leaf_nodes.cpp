#include<bits/stdc++.h>
#include"TREE-class.h"
using namespace std;
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)

int countleafnode(TreeNode<int>* root)
{
    if(root->children.size()==0)
    {
        return 1;
    }
    int ans=0;
    for(int i=0;i<root->children.size();i++)
    {
        ans+=countleafnode(root->children[i]);
    }
    return ans;
}
 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
TreeNode<int>*root=takeInputLevelwise();
cout<<countleafnode(root);
return 0;
}