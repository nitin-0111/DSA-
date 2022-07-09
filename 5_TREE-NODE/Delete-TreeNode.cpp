#include<bits/stdc++.h>
#include"TREE-class.h"
using namespace std;
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)
// 1 st Method
void deleteNode(TreeNode<int>* root)
{
    for(int i=0;i<root->children.size();i++)
    {
        deleteNode(root->children[i]);
    }
    delete root;
}
// 2 nd Method 
/* //In class making destector
~Treenode()
{
    for(int i=0;i<children.size();i++)
    {
        delete children[i];
    }
}
*/
 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);

return 0;
}