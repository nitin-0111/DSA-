 
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
 int output(Node *head,int n,int ct=0)
 {
     Node* temp=head;
     
     if(temp==NULL)
     {
         return -1;
     }
     if(temp->data==n)
     {
         return ct;
     }
     int x=output(temp->next,n,++ct);
     return x;
 }

 int main()
 {
     int t;
     cin>>t;
     while(t--){
         Node *head=takeinput_better();
         cout<<output(head,6);

     }
 }