#include<bits/stdc++.h>

using namespace std;
#include"BST.h"
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)


//  vector<int> ans;
//         stack<Node *> s1,s2;
//         bool changer =true;
//         s1.push(root);
//         while(!s1.empty())
//         {
//             Node *temp=s1.top();
//             s1.pop();
//             if(temp)
//             {
//                 ans.push_back(temp->data);
//                 if(changer)
//                 {
//                     if(temp->left)s2.push(temp->left);
//                     if(temp->right)s2.push(temp->right);
                    
//                 }
//                 else
//                 {
//                     if(temp->right)s2.push(temp->right);
//                     if(temp->left)s2.push(temp->left);
                    
//                 }
                
//                 if(s1.empty())
//                 {
//                     changer=!changer;
//                     swap(s1,s2);
                    
//                 }
//             }
//         }
//         return ans;
void zig_zig(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }
    stack<BinaryTreeNode<int>*>s1;

  bool changer=true;
    stack<BinaryTreeNode<int>*>s2;
    s1.push(root);
    while(!s1.empty()&&!s2.empty())
    {
        if(changer)
        {
            BinaryTreeNode<int>* topData=s1.top();
            s1.pop();
            cout<<topData->data<<" ";
            if(topData->right!=NULL)
            {
                s2.push(topData->right);
            }
            if(topData->left!=NULL)
            {
                s2.push(topData->left);
            }
            if(s1.empty())
            {
                cout<<endl;
                changer=!changer;
            }
        }
        if(!changer)
        {
            BinaryTreeNode<int>* topData=s2.top();
            s2.pop();
            cout<<topData->data<<" ";
            if(topData->left!=NULL)
            {
                s1.push(topData->left);
            }
            if(topData->right!=NULL)
            {
                s1.push(topData->right);
            }
            if(s2.empty())
            {
                cout<<endl;
                changer=!changer;
            }

        }
    }
}

 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
BinaryTreeNode<int>* root=takeinput_levelWise();
zig_zig(root);
return 0;
}