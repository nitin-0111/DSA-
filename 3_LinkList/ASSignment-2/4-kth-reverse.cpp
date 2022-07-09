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
        data = d;
        next = NULL;
    }
};
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node *takeinput_better()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {

            head = newnode;

            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}
Node *reverse_node(Node *head,Node* &tail)
{
if(head==NULL||head->next==NULL)
{
    return head;
}
Node* rest=reverse_node(head->next,head);
head->next->next=head;
head->next=NULL;
tail=head;
return rest;
  
}
Node* kth_reverse(Node* head,int k)
{
    Node*h1=head,*t1=head,*h2=NULL;
    int ct=0;
    if(head->next==NULL){
        return head;

    }
    while(ct!=k)
    {
        t1=t1->next;
        ct++;
    }
    h2=t1->next;
    h1=reverse_node(h1,t1);
    Node* rest=kth_reverse(h2,k);
    t1->next=rest;
    return(h1);

}

 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
Node * head=takeinput_better();
int k; cin>>k;
head=kth_reverse(head,k);
print(head);
return 0;
}