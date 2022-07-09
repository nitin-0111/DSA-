#include<bits/stdc++.h>

using namespace std;
#include"BST.h"
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)
//  MY CODE (NOT WORKING)
// vector<int>* find_path(BinaryTreeNode<int>* root,int x)
// {
//     if(root==NULL)
//     {
//         return NULL;
//     }
//     vector<int>* output;
//     if(x==root->data)
//     {
//         output->push_back(root->data);
//     output->push_back(root->data);
        

//     return output;
//     }

//     if(x>root->data)
//     output=find_path(root->right,x);
//     else if(x<root->data)
//     {
//         output =find_path(root->left,x);

//     output->push_back(root->data);
//     }
//     return output;

// }


//   LECTURE CODE
vector<int >* find_path(BinaryTreeNode<int>* root,int x)
{
    if(root==NULL)
    {
        return NULL;

    }
    if(root->data==x)
    {
        vector<int>* output =new vector<int>;
        output->push_back(root->data);
        return output;
    }
    vector<int>* leftoutput=find_path( root->left,x);
    if(leftoutput!=NULL)
    {
        leftoutput->push_back(root->data);
        return leftoutput;
    }
    vector<int>* rightoutput=find_path(root->right,x);
    if(rightoutput!=NULL)
    {
        rightoutput->push_back(root->data);
        return rightoutput;
    }
    else{
        return NULL;
    }
}

 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
BinaryTreeNode<int>* root=takeinput_levelWise();
vector<int>* output=find_path(root,2);
for(int i=0;i<output->size();i++)  
{
    cout<<output->at(i)<<" ";
}
return 0;
}