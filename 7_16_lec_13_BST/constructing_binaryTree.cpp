#include<bits/stdc++.h>

using namespace std;
#include"BST.h"

 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)
BinaryTreeNode<int>* construct_BST(int a[],int s,int e)
{
    if(s>e)
    {
        return NULL;
    }
   
    int mid=(e+s)/2;
    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(a[mid]);
    root->left=construct_BST(a,s,mid-1);
    root->right=construct_BST(a,mid+1,e);
    return root;
}
bool is_bst_3(BinaryTreeNode<int>* root,int min=INT_MIN, int max=INT_MAX)
{
    if(root==NULL){
        return true;
}
if(root->data<min||root->data>max)
{
    return false;
}
bool isleftok=is_bst_3(root->left,min,root->data-1);
bool isrightok =is_bst_3(root->right,root->data,max);
delete root;
return isleftok&&isrightok;

}

 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
int a[]={1,2,3,4,5,6,7,8,9};
BinaryTreeNode<int>* root=construct_BST(a,0,8);
printbinary_levelWise(root);
// cout<<is_bst_3(root);

return 0;
}