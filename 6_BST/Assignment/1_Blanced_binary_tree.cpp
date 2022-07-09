#include<bits/stdc++.h>

using namespace std;
#include"BST.h"
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)
//  METHOD-->1
// int height(BinaryTreeNode<int>* root)
// {
//     if(root==NULL)
//     {
//         return 0;
//     }
//     return 1+max(height(root->left),height(root->right));
// }
// bool isBalanced(BinaryTreeNode<int>* root)
// {
//     if(root==NULL)
//     {
//         return true;
//     }
//     return abs(height(root->left)-height(root->right))<2&&isBalanced(root->left)&&isBalanced(root->right);
// }
            // METHOD-->2
pair<int,bool> isBalanced_2(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        pair<int,bool>output;
        output.first=0;
        output.second=true;
        return output;
    }
    pair<int,bool>leftchild=isBalanced_2(root->left);
    pair<int,bool>rightchild=isBalanced_2(root->right);
    pair<int,bool>finaloutput;
    finaloutput.first=1+max(leftchild.first,rightchild.first);
    finaloutput.second=abs(leftchild.first-rightchild.first)<2&&leftchild.second&&rightchild.second;
    return finaloutput;
}        
bool helper(BinaryTreeNode<int>* root)
{
    return isBalanced_2( root).second;
}
 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
BinaryTreeNode<int>* root=takeinput_levelWise();
cout<<helper(root);
return 0;
}