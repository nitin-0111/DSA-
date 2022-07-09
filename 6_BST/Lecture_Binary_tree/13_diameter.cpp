#include<bits/stdc++.h>

using namespace std;
#include"BST.h"
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)
//  ISSKI TIME COMPEXICTY ==N*H
//   ORDERED TREE MAY N* LOG(N)   OR UNORDERED MAY N*N      {N*H}
int height(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+max(height(root->left),height(root->left));

}
int daimeter(BinaryTreeNode<int>* root)
{
      
    if(root==NULL)
    {
      
        return 0;
    }
    int h1=height(root->right),h2=height(root->left);
    int op1=h1+h2;
    int op2=daimeter(root->left);
    int op3=daimeter(root->right);
    return max(op1,max(op2,op3));
}
class Pair{
    public:
    int height ;
    int diameter;
};
Pair daimeter_better(BinaryTreeNode<int>* root)
{
    Pair ans;
    if(root==NULL)
    {
        ans.diameter=0;
        ans.height=0;
    return ans;
    }
    Pair left=daimeter_better(root->left);
    Pair right=daimeter_better(root->right);
    ans.diameter=max(left.height+right.height,max(left.diameter,right.diameter));
    ans.height=1+max(left.height,right.height);
    return ans;
}
 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
BinaryTreeNode<int>* root=takeinput_levelWise();
Pair ans=daimeter_better(root);
cout<<ans.height<<" "<<ans.diameter;
return 0;
}