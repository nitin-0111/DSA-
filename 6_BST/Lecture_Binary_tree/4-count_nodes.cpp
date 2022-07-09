#include<bits/stdc++.h>
using namespace std;
#include"BST.h"
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)
int count(BinaryTreeNode<int>* root)
{
    if(root==NULL){
        return 0;
    }
    int ans=1;
    ans+=count(root->left);
    ans+=count(root->right);
    return ans;
}

 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
BinaryTreeNode<int>* root=takeinput_levelWise();
cout<<count(root);
return 0;
}