#include<bits/stdc++.h>

using namespace std;
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)
#include"1_Linklist-class-1.cpp"

 Node* takeinput()
 {
     int data ;
     cin>>data;
     Node*head=NULL;
     while(data!=-1)
     {
         Node* newnode=new Node(data);
         if(head==NULL)
         {
             head=newnode;
         }
         else{
             Node* temp=head;
             while(temp->next!=NULL)
             {
                 temp=temp->next;
             }
             temp->next=newnode;
         }
         cin>>data;

     }
     return head;
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

 ///    #insert new element
 Node* insert(Node* head,int i,int data)
 {
     Node*newnode=new Node(data);
     int count=0;
     Node* temp=head;
     if(i==0)
     {
         newnode->next=head;
         head=newnode;
         return head;
     }
     while(temp!=NULL&&count<i-1)
     {
         temp=temp->next;
         count++;
     }
     if(temp!=NULL)
     {
         newnode->next=temp->next;
         temp->next=newnode;
     }
     else cout<<" limit accessed!!"<<endl;
     return head;
 }
 ////       insertion by recursive method
 Node* insert_recursive(Node* head,int i,int data)
 {  Node *temp=head;
     if(temp==NULL)
     {
         return head;
     }
     Node* x=insert_recursive(temp->next,i-1,data);
      head->next=x;
         Node * newnode=new Node(data);
     if(i==0)
     {
         newnode->next=head;
        head=newnode;
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

 void print( Node *head)
 {
     Node*temp=head;
     while(temp!=NULL){
         cout<<temp->data<<" ";
         temp=temp->next;
     }
     cout<<endl;
 }
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
Node*head=takeinput_better();
print(head);
// head=insert_recursive(head,2,99);
head=deletenode_recursive(0,head);
print(head);
return 0;
}