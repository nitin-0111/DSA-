#include<bits/stdc++.h>

using namespace std;
#include"BST.h"
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)
BinaryTreeNode<int>* delete_leaf(BinaryTreeNode<int>* root)
{
  if(root==NULL){
    return NULL;
  }
  if(root->left==NULL&&root->right==NULL)
  {
    delete root;
   return NULL;
  }
BinaryTreeNode<int>* leftpart=delete_leaf(root->left);
BinaryTreeNode<int>* rightpart=delete_leaf(root->right);
root->left=leftpart;
root->right=rightpart;
return root;


    
}

 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
BinaryTreeNode<int>* root=takeinput_levelWise();
delete_leaf(root);
printbinary_levelWise(root);
return 0;
}