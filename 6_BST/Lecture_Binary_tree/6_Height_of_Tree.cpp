#include<bits/stdc++.h>
using namespace std;
#include"BST.h"
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)
///         KUCH PRINT HE NHI HO RHA H ALSA KYU HOTA H
int Height(BinaryTreeNode<int>* root)
{
    if(root->left->data==-1||root->right->data==-1)
    {
        return 0;
    }
    int ans;
    int LeftHeight=Height(root->left);
    int RightHeight=Height(root->right);
    ans+=max(LeftHeight,RightHeight);
    return ans+1;
}

 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
BinaryTreeNode<int>* root=takeinput_levelWise();
int H=Height(root);
cout<<H;
return 0;
}