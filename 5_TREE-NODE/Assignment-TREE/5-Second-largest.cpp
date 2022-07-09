#include<bits/stdc++.h>
#include "TREE-class.h"
using namespace std;
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)
class Pair{
    public:
    int M;
    int SM;
    Pair(){

    }
    Pair(int rootData):M(rootData),SM(-1){

    }
    
 };
Pair second_largest(TreeNode<int >* root)
{
    static Pair ans(root->data);
    
    for(int i=0;i<root->children.size();i++)
    {
        Pair temp=second_largest(root->children[i]);
        if(ans.M<temp.M)
        {
            int t=ans.M;
            ans.M=temp.M;
            ans.SM=max(t,temp.SM);
        }
        else{
            ans.SM=max(temp.M,ans.SM);

        }
    }
    return ans;
    
}
int sec(TreeNode<int >* root)
{
    Pair ans=second_largest(root);
    return ans.SM;
}

 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
TreeNode<int>* root=takeInputLevelwise();
cout<<sec(root);
return 0;
}