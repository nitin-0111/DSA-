#include <bits/stdc++.h>
#include "TREE-class.h"
using namespace std;
#define ll long long
#define loop(i, a, n) for (int i = a; i < n; i++)
bool strcturally_indical(TreeNode<int> *root1, TreeNode<int> *root2)
{
   bool ans;
  int child2 = root2->data;
  int child1 = root1->data;
  int size1 = root1->children.size();
  int size2=root2->children.size();
  if (child1 != child2||size1!=size2)
  {
    ans = false;
    return ans;
  }
  else
  ans=true;
  return ans;
  for (int i = 0; i < root1->children.size(); i++)
  {
    bool x = strcturally_indical(root1->children[i], root2->children[i]);
    ans = x;
  }
  return ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  TreeNode<int> *root1 = takeInputLevelwise();
  TreeNode<int> *root2 = takeInputLevelwise();
  cout << strcturally_indical(root1, root2);

  return 0;
}