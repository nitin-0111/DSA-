#include<bits/stdc++.h>
#include "TREE-class.h"
using namespace std;
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)

int Next_larger_value(int x,TreeNode<int>* root)
{
    int ans;
    if(root->data==10)
    { ans=-1;}
    for(int i=0;i<root->children.size();i++)
    {
        int temp=Next_larger_value(x,root->children[i]);
        
        
            if(temp>=x)
            {
                if(ans==-1)
                {ans=temp;}
                else if(temp<ans)
                {
                    ans=temp;
                }

            }
        
    }
    return ans;
}
 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
int x;
cin>>x;
TreeNode<int>* root=takeInputLevelwise();
cout<<Next_larger_value(x,root);
return 0;
}