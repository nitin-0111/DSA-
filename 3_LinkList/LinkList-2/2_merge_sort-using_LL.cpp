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
 Node* e(Node* h1,Node* h2)
 {
     Node* head=NULL;
     Node* tail =NULL;
     while(h1!=NULL&&h2!=NULL)
     {
         if( h2->data>=h1->data)
         {
             if( head==NULL)
             {
                 head=h1;
                 tail=h1;
             }
             else{
                 tail->next=h1;
                 tail=h1;
             }
                 h1=h1->next;
         }
         else{
             if( head==NULL)
             {
                 head=h2;
                 tail=h2;
             }
             else{
                 tail->next=h2;
                 tail=h2;
             }
             h2=h2->next;
         }

     }
     if( h2==NULL)
     {
         tail->next=h1;
     }
     else 
    { tail->next=h2;}


     return head;
 }
 Node* midpointer(Node* head)
 {
     Node * temp=head;
     Node * slow=temp;
     Node * fast=temp;
     while( fast->next!=NULL&&fast->next->next!=NULL)
     {
         slow=slow->next;
         fast=fast->next->next;
     }
     return slow;

 }
 Node* esort(Node* head)
 {
     Node* temp=head;
     if( temp->next==NULL||temp==NULL)
     {
         return head;
     }
      Node*mid=midpointer(head);
      Node* l2=mid->next;
      Node* l1=head;
     mid->next = NULL;
     Node* part1=NULL,*part2=NULL;
     part1=esort(l1);
     part2=esort(l2);
     return(e(part1,part2));
 }
 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
Node* head=takeinput_better();
head=esort(head);
print(head);
return 0;
}