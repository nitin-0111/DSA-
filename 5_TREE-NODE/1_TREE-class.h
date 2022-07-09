#include <vector>
#include<iostream>
using namespace std;

template<typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode*> children;
    TreeNode(T data)
    {
        this->data=data;
    }
};

TreeNode<int>* takeInputLevelwise()
{
   int rootdata;
   cout<<"Ente rootdata"<<endl;
   cin>>rootdata;
   TreeNode<int>* root=new TreeNode<int>(rootdata);
   queue<TreeNode<int>*>pending;
   pending.push(root);
   while(pending.size()!=0)
   {
       TreeNode<int>* front=pending.front();
       pending.pop();
       cout<<"num of child of"<<front->data<<endl;
       int numchild;
       cin>>numchild;
       for(int i=0;i<numchild;i++)
       {
           int chidData;
           cout<<"Enter data of "<<i+1<<"th child of "<< front->data<<endl;
           cin>>chidData;
           TreeNode<int>* child=new TreeNode<int>(chidData);
           front->children.push_back(child);
           pending.push(child);

       }
   }
   return root;

}
 void printTreenLevelWise(TreeNode<int>* root)
    {
        if(root==NULL)
        {
            return;
        }
        queue<TreeNode<int>*> pendingToPrint;
        pendingToPrint.push(root);
        while(pendingToPrint.size()!=0)
        {
            TreeNode<int>* front=pendingToPrint.front();
            pendingToPrint.pop();
            cout<<front->data<<":";
            for(int i=0;i<front->children.size();i++)
            {
                cout<<front->children[i]->data<<",";
                pendingToPrint.push(front->children[i]);
            }
            cout<<endl;
        }
    }