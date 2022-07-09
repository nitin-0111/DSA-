// #include<bits/stdc++.h>

// using namespace std;
// #include"BST.h"
//  #define ll long long
// #define loop(i,a,n) for(int i=a;i<n;i++)

// BinaryTreeNode<int>* construting_tree(int *pre,int *in,int pre_S,int pre_E,int in_S,int in_E )
// {
//     if(pre_S>pre_E){
//         return NULL; 

//     }
//     int L_in_S,L_in_E,R_in_S,R_in_E,L_pre_S,L_pre_E,R_pre_S,R_pre_E;
//     int root,I;
//     L_in_S=in_S;
//     root=pre_S;
    
//     BinaryTreeNode<int>* Root=new BinaryTreeNode<int>(pre[root]);
//     L_pre_S=root+1;
//     for(int i=in_S;i<=in_E;i++)
//     {
//         if(pre[root]==in[i])
//         {
//             I=i;
//             break;
//         }

//     }
//     L_in_E=I-1;
//     R_in_S=I+1;
//     R_in_E=in_E;
//     L_pre_E=(L_in_E-L_in_S)+L_pre_S;
//     R_pre_S=L_pre_E+1;
//     R_in_E=pre_E;
//     Root-> left=construting_tree(pre,in,L_pre_S,L_pre_E,L_in_S,L_in_E);
//     Root->right=construting_tree(pre,in,R_pre_S,R_pre_E,R_in_S,R_in_E);
//     // Root->left=left;
//     // Root->right=right;
//     return(Root);
// }
 
// int main ()
// {
//   ios_base::sync_with_stdio(false);
// cin.tie(NULL);
// int n=7;
// // cin>>n;
// int pre[]= {1, 2, 4, 5, 3, 6, 7 };//new int[n];
// int  in[] ={ 4, 2, 5, 1, 6, 3, 7};//new int[n];
// // for(int i=0;i<n;i++)
// // {
// //     cin>>pre[i];
// // }
// // for(int i=0;i<n;i++)
// // {
// //     cin>>in[i];
// // }
// BinaryTreeNode<int>*root=construting_tree(pre,in,0,n-1,0,n-1);
// printbinary_levelWise(root);
// return 0;
// }


//          VIDEO SOLUTION
#include<bits/stdc++.h>

using namespace std;
#include"BST.h"
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)

BinaryTreeNode<int>* buildTreeHelper(int *in,int *pre,int inS,int inE,int preS,int preE)
{
    if(inS>inE)
    {
        return NULL;
    }
    int rootData=pre[preS];
    int rootIndes=-1;
    for(int i=inS;i<=inE;i++)
    {
        if(in[i]==rootData)
        {
            rootIndes=i;
            break;
        }
    }
    int lIns=inS;
    int lInE=rootIndes-1;
    int lPreS=preS+1;
    int lPreE=lInE-lIns+lPreS;
    int rPres=lPreE+1;
    int rPreE=preE;
    int rInS=rootIndes+1;
    int rInE=inE;
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
    root->left=buildTreeHelper(in,pre,lIns,lInE,lPreS,lPreE);
    root->right=buildTreeHelper(in,pre,rInS,rInE,rPres,rPreE);
    return root;
}
 BinaryTreeNode<int>* buildTree(int * in,int *pre,int size){
     return buildTreeHelper(in,pre,0,size-1,0,size-1);
 }
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
int in[]={4,2,5,1,8,6,9,3,7};
int pre[]={1,2,4,5,3,6,8,9,7};
BinaryTreeNode<int>*root=buildTree(in,pre,9);
printbinary_levelWise(root);
return 0;
}