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