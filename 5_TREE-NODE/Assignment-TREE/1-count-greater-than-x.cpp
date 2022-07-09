#include<bits/stdc++.h>
#include"TREE-class.h"
using namespace std;
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)

int count_greater_x(int x,TreeNode<int>* root)
{
    int ct=0;
    for(int i=0;i<root->children.size();i++)
    {
        ct+=count_greater_x(x,root->children[i]);
    }
    if(root->data>=x)
    {
        ct++;
        return ct;
    }
    return ct;

}
 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
int x;
cin>>x;
TreeNode<int>* root=takeInputLevelwise();
cout<<count_greater_x(x,root);
return 0;
}