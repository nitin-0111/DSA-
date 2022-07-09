#include <bits/stdc++.h>

using namespace std;
#include "BST.h"
#define ll long long
#define loop(i, a, n) for (int i = a; i < n; i++)
///         KUCH PRINT HE NHI HO RHA H ALSA KYU HOTA H
bool IsPREsent(BinaryTreeNode<int> *root, int x)
{

  if (x == root->data)
  {

    return x == root->data;
  }

  return (IsPREsent(root->left, x) || IsPREsent(root->right, x));
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int x;
  cin >> x;
  BinaryTreeNode<int> *root = takeinput_levelWise();
  // printbinary_levelWise(root);
  // cout<<endl<<endl<<endl<<"output:";
  cout << "output: " << IsPREsent(root, x) << endl;

  return 0;
}