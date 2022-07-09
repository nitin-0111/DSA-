#include<bits/stdc++.h>
#include"TREE-class.h"
#include<queue>
using namespace std;
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)
TreeNode<int>* takeinput()
{
    int rootdata;
    cout<<"Enter data "<<endl;
    cin>>rootdata;
    TreeNode<int>* root=new TreeNode<int>(rootdata);
    int n;
    cout<<" Enter num of childern of "<<rootdata<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        TreeNode<int>*child=takeinput();
        root->children.push_back(child);
    }
   return root;
}
TreeNode<int>* takeInputLevelwise()
{
   int rootdata;
   cout<<"Ente rootdata"<<endl;
   cin>>rootdata;
   TreeNode<int>* root=new TreeNode<int>(rootdata);
   queue<TreeNode<int>*>pending;
   pending.push(root);
   while(pending.size()!=0)
   {
       TreeNode<int>* front=pending.front();
       pending.pop();
       cout<<"num of child of"<<front->data<<endl;
       int numchild;
       cin>>numchild;
       for(int i=0;i<numchild;i++)
       {
           int chidData;
           cout<<"Enter data of "<<i+1<<"th child of"<< front->data<<endl;
           cin>>chidData;
           TreeNode<int>* child=new TreeNode<int>(chidData);
           front->children.push_back(child);
           pending.push(child);

       }
   }
   return root;

}
void printTreen(TreeNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++)
    {
        cout<<root->children[i]->data<<" ,";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++)
    {
        printTreen(root->children[i]);
    }
}

    void printTreenLevelWise(TreeNode<int>* root)
    {
        if(root==NULL)
        {
            return;
        }
        queue<TreeNode<int>*> pendingToPrint;
        pendingToPrint.push(root);
        while(pendingToPrint.size()!=0)
        {
            TreeNode<int>* front=pendingToPrint.front();
            pendingToPrint.pop();
            cout<<front->data<<":";
            for(int i=0;i<front->children.size();i++)
            {
                cout<<front->children[i]->data<<",";
                pendingToPrint.push(front->children[i]);
            }
            cout<<endl;
        }
    }
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
TreeNode<int>*root=takeInputLevelwise();
printTreenLevelWise(root);
return 0;
//TODO 
}