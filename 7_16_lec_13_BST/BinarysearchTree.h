#include "BST.h"
class BST
{
    BinaryTreeNode<int> *root;

public:
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }

private:
    BinaryTreeNode<int> *deleteData(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            return NULL;
        }
        if (data > node->data)
        {
            node->right = deleteData(data, node->right);
            return node;
        }
        else if (data < node->data)
        {
            node->left = deleteData(data, node->left);
            return node;
        }
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }
            else if (node->left == NULL)
            {
                BinaryTreeNode<int> *temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else if (node->right == NULL)
            {
                BinaryTreeNode<int> *temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else
            {
                BinaryTreeNode<int> *minNode = node->right;
                while (minNode->left != NULL)
                {
                    minNode = minNode->left;
                }
                int rightmin = minNode->data;
                node->data = rightmin;
                node->right = deleteData(rightmin, node->right);
                return node;
            }
        }
    }

public:
    void deleteData(int data)
    {
        this->root = deleteData(data, root);
    }

private:
    BinaryTreeNode<int> *insert(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            BinaryTreeNode<int> *newnode = new BinaryTreeNode<int>(data);
            return newnode;
        }
        if (node->data <= data)
        {
            node->right = insert(data, node->right);
        }
        else
        {
            node->left = insert(data, node->left);
        }

        return node;
    }

public:
    void insert(int data)
    {
        this->root = insert(data, this->root);
    }

private:
    bool hasData(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            return false;
        }
        if (node->data == data)
        {
            return true;
        }
        else if (data < root->data)
        {
            return hasData(data, node->left);
        }
        else
        {
            return hasData(data, node->right);
        }
    }

public:
    bool hasData(int data)
    {
        return hasData(data, root);
    }
    void print()
    {
        printbinary_levelWise(this->root);
    }

    void printbinary_levelWise(BinaryTreeNode<int> *root)
    {
        if (root == NULL)
        {
            return;
        }
        queue<BinaryTreeNode<int> *> pending;
        pending.push(root);
        while (pending.size() != 0)
        {
            BinaryTreeNode<int> *front = pending.front();
            pending.pop();
            cout << front->data << ":"; //<<"L "<<front->left->data<<","<<"R "<<front->right->data<<endl;
            if (front->left != NULL)
            {
                cout << "L " << front->left->data;
                pending.push(front->left);
            }
            else
                cout << "-1";
            if (front->right != NULL)
            {
                cout << ","
                     << "R " << front->right->data << endl;
                pending.push(front->right);
            }
            else
                cout << "-1" << endl;
        }
    }
};