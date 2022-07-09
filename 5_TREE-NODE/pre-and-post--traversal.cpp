#include<bits/stdc++.h>
#include"TREE-class.h"
using namespace std;
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)
void pre(TreeNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++)
    {
        pre(root->children[i]);

    }
}
void post(TreeNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }
    for(int i=0;i<root->children.size();i++)
    {
        post(root->children[i]);

    } 
    cout<<root->data<<" ";
}

 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
TreeNode<int>* root=takeInputLevelwise();
pre(root);
cout<<endl;
post(root);
return 0;
}