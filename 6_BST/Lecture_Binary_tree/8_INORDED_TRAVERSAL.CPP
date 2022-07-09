#include<bits/stdc++.h>

using namespace std;
#include"BST.h"
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)
void Inorderde(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }
    
    Inorderde(root->left);
    //cout<<endl;
    cout<<root->data<<" ";
    Inorderde(root->right);
    //cout<<endl;
}

 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
BinaryTreeNode<int>* root=takeinput_levelWise();
Inorderde( root);
return 0;
}