#include<bits/stdc++.h>

using namespace std;
#include"BST.h"
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)
void R_printbinary_levelWise(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int>*>pending;
    pending.push(root);
    while(pending.size()!=0)
    {
        BinaryTreeNode<int>* front=pending.front();
        pending.pop();
         cout<<front->data<<":";//<<"L "<<front->right->data<<","<<"R "<<front->right->data<<endl;
        if(front->right!=NULL)
        {
            cout<<"L "<<front->right->data;
        pending.push(front->right);
        }
        else
        cout<<"-1";
        if(front->left!=NULL)
        {
            cout<<","<<"R "<<front->left->data<<endl;
        pending.push(front->left);
        }
        else
        cout<<"-1"<<endl;


    }
}

 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
BinaryTreeNode<int>* root=takeinput_levelWise();
R_printbinary_levelWise(root);
return 0;
}