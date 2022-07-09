#include<bits/stdc++.h>

using namespace std;
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)

   class Node
{
    public:
    Node *next;
    int data;
    Node(int d)
    {
        data=d;
        next=NULL;
    }

};
 void print( Node *head)
 {
     Node*temp=head;
     while(temp!=NULL){
         cout<<temp->data<<" ";
         temp=temp->next;
     }
     cout<<endl;
 }
Node* takeinput_better()
 {
     int data ;
     cin>>data;
     Node*head=NULL;
     Node*tail=NULL;
     while(data!=-1)
     {
         Node* newnode=new Node(data);
         if(head==NULL)
         {

             head=newnode;

             tail=newnode;
             
         }
         else{
             tail->next=newnode;
             tail=tail->next;
           
         }
         cin>>data;

     }
     return head;
 }
 Node* deletenode_recursive(int i,Node* head)
 {
     Node* temp=head;
     if(temp==NULL)
     {
         return head;
     }
     Node* x=deletenode_recursive(i-1,temp->next);
     head->next=x;
     if(i==0)
     {
         head=temp->next;
     }
     return head;
 }

 
 Node* eliminateduplicate(Node * head)
 {
     Node* temp=head;
     int ct=0;
     while( temp!=NULL)
     {
         if(temp->data!=(temp->next)->data)
         {
             temp=temp->next;
         }
         else{

             temp=deletenode_recursive(ct,temp);
             ct=0;
         }
             ct++;
     }
     return temp;
 }
 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
Node* head=takeinput_better();
head=eliminateduplicate(head);
print(head);
return 0;
}