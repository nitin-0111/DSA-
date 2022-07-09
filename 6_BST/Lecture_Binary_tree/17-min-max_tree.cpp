#include<bits/stdc++.h>

using namespace std;
#include"BST.h"
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)
pair<int,int> max_min(BinaryTreeNode<int>* root)
{
    if(root->left==NULL&&root->right==NULL)
    {
        pair<int,int>ans;
        ans.first=root->data;
        ans.second=root->data;
        return ans;
    }
    pair<int,int>left=max_min(root->left);

    pair<int,int>right=max_min(root->right);
    pair<int,int>ans;
    ans.first=max(left.first,max(right.first,root->data));
    ans.second=min(left.second,min(right.second,root->data));
    return ans;
}

 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
BinaryTreeNode<int>* root=takeinput_levelWise();
pair<int,int>ans=max_min(root);
cout<<endl;
cout<<ans.first<<" "<<ans.second;
return 0;
}