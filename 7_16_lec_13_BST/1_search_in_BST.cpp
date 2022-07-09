#include<bits/stdc++.h>

using namespace std;
#include"BST.h"
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)
bool search_in_BST(BinaryTreeNode<int>* root,int x)
{
    if(root==NULL)
    {
        return false;

    }
    if(root->data==x)
    {
        return true;
    }
 
 bool ans;
    //BinaryTreeNode<int>* ans;
    if(root->data<x)
    {
        ans= search_in_BST(root->left,x);
    }
    
    else if(root->data>x)
    {
       ans=search_in_BST(root->right,x);
    }
        return ans;
}

 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
BinaryTreeNode<int>* root=takeinput_levelWise();
bool ans=search_in_BST(root,2);
cout<<ans;
return 0;
}