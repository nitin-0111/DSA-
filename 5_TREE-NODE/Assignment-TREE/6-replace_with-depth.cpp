#include<bits/stdc++.h>
#include "TREE-class.h"
using namespace std;
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)

void replace(TreeNode<int>*& root,int depth=0)
{
    root->data=depth;
    for(int i=0;i<root->children.size();i++)
    {
        replace(root->children[i],depth+1);
    }
    
}
 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
TreeNode<int>* root=takeInputLevelwise();
replace(root);
printTreenLevelWise(root);
return 0;
}