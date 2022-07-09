#include<bits/stdc++.h>

using namespace std;
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)
int n=0;
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
             n++;
         }
         else{
             tail->next=newnode;
             tail=tail->next;
             n++;
         }
         cin>>data;

     }
     return head;
 }
 Node* prepointer(Node* head,int i)
 {
     Node* temp=head;
     int ct=1;
     while(i!=ct)
     {
         if(temp!=NULL){
             temp=temp->next;
             ct++;

         }
             

     }
     return temp;

 }
 Node* appendrecursive(Node*head,int i)
 {
     if(n==i)
     {
         return head;
     }
     Node* pre=prepointer(head,n-1);
     Node* cur=pre->next;
     Node* x=appendrecursive(head,i-1);
     head->next=x;
     if(i==1)
     {
         cur->next=head;
         pre->next=NULL;
         head=cur;
     }
     return head;
 }
 Node* AppendlastNtoF(Node* head,int i)
 {
    //  if(n==i)
    //  {
    //      return head;
    //  }
     Node*pre=prepointer(head,n-i);
     Node*tail=prepointer(head,n);
     Node* newhead=pre->next;
     tail->next=head;
     pre->next=NULL;
     return newhead;
     

    //  Node*x=AppendlastNtoF(head,i-1);
    //  head->next=x;
    //  if(i==1)
    //  {
    //      pre->next=NULL;
    //      cur->next=head;
    //      head=cur;
    //  }
    // return head;
 }

int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
Node* head=takeinput_better();

int i;cin>>i;
head=appendrecursive(head,i);
print(head);
return 0;
}