#include<bits/stdc++.h>
#include"TREE-class.h"
using namespace std;
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)
int sum(TreeNode<int>* root)
{
    int ans=0;
    ans=root->data;
    for(int i=0;i<root->children.size();i++)
    {
        ans+=root->children[i]->data;
    }
    return ans;
}
TreeNode<int>* NOdeWithMAX_sum(TreeNode<int>* root)
{
    int rootsum=sum(root);
    TreeNode<int>* ans=root;
    TreeNode<int>*x;
    int childsum;
    for(int i=0;i<root->children.size();i++)
    {
        childsum=sum(root->children[i]);
        x=NOdeWithMAX_sum(root->children[i]);
        if(childsum>rootsum)
        {
         ans=x;
         rootsum=max(rootsum,childsum);

        }
    }
    return( ans);
}

 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
TreeNode<int>* root=takeInputLevelwise();
cout<<NOdeWithMAX_sum(root)->data;
cout<<endl;
printTreenLevelWise(root);
return 0;
}