#include<bits/stdc++.h>

using namespace std;
#include"E:\c++\self_practice\DSA cn\LinkList\LinkList-2\NODE.h"
 #include"BST.h"
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)

pair<Node*,Node*> BST_to_ll(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        pair<Node*,Node*> output;
        output.first=NULL;
        output.second=NULL;
        return output;
    }
    pair<Node*,Node*> leftoutput=BST_to_ll(root->left);
    pair<Node*,Node*> rightoutput=BST_to_ll(root->right);
    Node* rootnode=new Node(root->data);
    leftoutput.second->next=rootnode;
    rootnode->next=rightoutput.first;
    pair<Node*,Node*> output;
    output.first=leftoutput.first;
    output.second=rightoutput.second;
    return output;
}
 Node* helper(BinaryTreeNode<int>* root){
 Node* head=BST_to_ll(root).first;
 return head;}
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
BinaryTreeNode<int>* root=takeinput_levelWise();
Node *head=helper(root);
print(head);


return 0;
}