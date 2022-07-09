#include <bits/stdc++.h>

using namespace std;
#include "BST.h"
#include "E:\c++\self_practice\DSA cn\LinkList\LinkList-2\NODE.h"
#define ll long long
#define loop(i, a, n) for (int i = a; i < n; i++)
vector<Node *> levelWiseLL(BinaryTreeNode<int> *root)
{

  if (root == NULL)
  {
    vector<Node *> output;
    output.push_back(NULL);
    return output;
  }
  vector<Node *> output;
  queue<BinaryTreeNode<int> *> pending;
  pending.push(root);
  pending.push(NULL);
  Node *head = NULL;
  Node *tail = NULL;
  while (pending.size() != 0)
  {
    BinaryTreeNode<int> *frontroot = pending.front();
    pending.pop();
    if (frontroot != NULL)
    {
      Node *newnode = new Node(frontroot->data);
      if (head == NULL)
      {
        head = newnode;
        tail = newnode;
      }
      else
      {
        tail->next = newnode;
        tail = tail->next;
      }
      if (frontroot->left != NULL)
      {
        pending.push(frontroot->left);
      }
      if (frontroot->right != NULL)
      {
        pending.push(frontroot->right);
      }
    }
    if (pending.size() == 0)
    {tail->next = NULL;
      output.push_back(head);
      head = NULL;
      tail = NULL;
      break;
    }
    if (frontroot == NULL)
    {
      tail->next = NULL;
      output.push_back(head);
      head = NULL;
      tail = NULL;
      pending.push(NULL);
    }
  }
  return output;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  BinaryTreeNode<int> *root = takeinput_levelWise();
  vector<Node *> output = levelWiseLL(root);
  for (int i = 0; i <= output.size(); i++)
  {
    print(output[i]);
  }

  return 0;
}