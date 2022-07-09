#include <bits/stdc++.h>

using namespace std;
#include "BST.h"
#define ll long long
#define loop(i, a, n) for (int i = a; i < n; i++)
void print_level_wise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> pending;
    pending.push(root);
    pending.push(NULL);
    while (pending.size() != 0)
    {
        BinaryTreeNode<int> *frontroot = pending.front();
        pending.pop();
        if(pending.size()==0)
        {
            break;
        }
        if (frontroot != NULL)
        {
            cout << frontroot->data<<" ";
            if (frontroot->left != NULL)
            {
                pending.push(frontroot->left);
            }
             if (frontroot->right != NULL)
            {
                pending.push(frontroot->right);
            }
        }
        else
        {
            cout << endl;
            pending.push(NULL);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    BinaryTreeNode<int> *root = takeinput_levelWise();
    print_level_wise(root);
    return 0;
}