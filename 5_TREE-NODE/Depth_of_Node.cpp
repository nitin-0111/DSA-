#include<bits/stdc++.h>
#include"TREE-class.h"
using namespace std;
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)
void printkthlevel(TreeNode<int>* root,int k)
{
    if(root==NULL)
    {
        return ;
    }
    if(k==1)
    {
        cout<<root->data<<" ";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++)
    {
        printkthlevel(root->children[i],k-1);
    }
}

 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
TreeNode <int>* root =takeInputLevelwise();
printkthlevel(root,2);

return 0;
}