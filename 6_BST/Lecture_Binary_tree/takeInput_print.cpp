#include<bits/stdc++.h>
#include"BST.h"

using namespace std;
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)
void printbinary(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<":";
    if(root->left!=NULL)
    {
        cout<<" L "<<root->left->data;
    }
    if(root->right!=NULL)
    {
        cout<<" R "<<root->right->data;
    }
    cout<<endl;
    printbinary(root->left);
    printbinary(root->right);
    
}
BinaryTreeNode<int>* takeinput_levelWise()
{
    int rootdata;
    cout<<"Enter root data"<<endl;
    cin>>rootdata;
    if(rootdata==-1)
    {
        return NULL;
    }
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootdata);
    queue<BinaryTreeNode<int>*> pending;
    pending.push(root);
    while(pending.size()!=0)
    {
        BinaryTreeNode<int>* front=pending.front();
        pending.pop();
        int leftchild;
        cout<<"Enter data for left child of"<<front->data<<endl;
        cin>>leftchild;
        if(leftchild!=-1){
        BinaryTreeNode<int>* Lchild=new BinaryTreeNode<int>(leftchild);
        front->left=Lchild;
        pending.push(Lchild);
        }
        int rightchild;
        cout<<"Enter data for right child of"<<front->data<<endl;
        cin>>rightchild;
        if(rightchild!=-1){
        BinaryTreeNode<int>* Rchild=new BinaryTreeNode<int>(rightchild);
        front->right=Rchild;
        pending.push(Rchild);
        }
    }
    return root;
}
BinaryTreeNode<int>* takeinput()
{
    int rootdata;
    cout<<"Enter data"<<endl;
    cin>>rootdata;
    if(rootdata==-1)
    {
        return NULL;
    }
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootdata);
    BinaryTreeNode<int>*leftchild=takeinput();
    BinaryTreeNode<int>* rightchild=takeinput();
    root->left=leftchild;
    root->right=rightchild;
return root;
} 
void printbinary_levelWise(BinaryTreeNode<int>* root)
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
         cout<<front->data<<":";//<<"L "<<front->left->data<<","<<"R "<<front->right->data<<endl;
        if(front->left!=NULL)
        {
            cout<<"L "<<front->left->data;
        pending.push(front->left);
        }
        else
        cout<<"-1";
        if(front->right!=NULL)
        {
            cout<<","<<"R "<<front->right->data<<endl;
        pending.push(front->right);
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
printbinary_levelWise(root);
return 0;
}