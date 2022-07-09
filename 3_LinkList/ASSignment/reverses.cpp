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
 void revrse_print(Node* head)
 {
     if(head==NULL)
     {
         return;
     }
    if(head->next==NULL)
    {
        // cout<<head->data<<" ";
    }
    revrse_print( head->next);
    cout<<head->data<<" ";
 }
 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
Node* head=takeinput_better();
revrse_print(head);
return 0;
}