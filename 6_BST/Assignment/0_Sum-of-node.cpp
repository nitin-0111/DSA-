#include<bits/stdc++.h>

using namespace std;
#include"BST.h"

 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)
int sumOfNOde(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int leftsum=sumOfNOde(root->left);
    int rightsum=sumOfNOde(root->right);
    return root->data+leftsum+rightsum;
}

 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
BinaryTreeNode<int>* root=takeinput_levelWise();
cout<<sumOfNOde(root);
return 0;
}