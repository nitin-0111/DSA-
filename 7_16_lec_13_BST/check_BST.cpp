#include<bits/stdc++.h>

using namespace std;
#include"BST.h"
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)
int minum(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return INT_MAX;
    }
    return min(root->data,min(minum(root->left),minum(root->right)));

}
int maxum(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return INT_MIN;
    }
    return max(root->data,max(maxum(root->left),maxum(root->right)));
}
// bool isBST(BinaryTreeNode<int>* root)
// {
//     if(root==NULL)
//     {
//         return true;
//     }
//     int leftmax=maxum(root->left);
//     int rightmin=minum(root->right);

//     bool output=(leftmax<root->data)&&(rightmin>=root->data)&&(isBST(root->left))&& (isBST(root->right));
//     return output;
// }
class triple{
    public:
    bool isBST;
    int minimum;
    int maximum;

};
triple isBST_improved(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        triple output;
        output.isBST=true;
        output.minimum=INT_MAX;
        output.maximum=INT_MIN;
        return output;
    }
    triple leftoutput=isBST_improved(root->left);
    triple rightoutput=isBST_improved(root->right);
    triple output;
    output.minimum=min(root->data,min(leftoutput.minimum,rightoutput.minimum));
    output.maximum=max(root->data,max(rightoutput.maximum,leftoutput.maximum));
    output.isBST=(root->data>leftoutput.maximum)&&(root->data<=rightoutput.minimum)&&leftoutput.isBST&&rightoutput.isBST;
    return output;
}
bool helper(BinaryTreeNode<int>* root)
{
    return isBST_improved(root).isBST;
}
bool is_bst_3(BinaryTreeNode<int>* root,int min=INT_MIN, int max=INT_MAX)
{
    if(root==NULL){
        return true;
}
if(root->data<min||root->data>max)
{
    return false;
}
bool isleftok=is_bst_3(root->left,min,root->data-1);
bool isrightok =is_bst_3(root->right,root->data,max);
delete root;
return isleftok&&isrightok;

}

 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);

BinaryTreeNode<int>* root=takeinput_levelWise();
cout<<helper(root);
return 0;
}