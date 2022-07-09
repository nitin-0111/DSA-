#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define loop(i, a, n) for (int i = a; i < n; i++)

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
Node *midpointer(Node *head)
{
    Node *temp = head;
    Node *slow = temp;
    Node *fast = temp;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node *reverse_node(Node *head)
{
if(head==NULL||head->next==NULL)
{
    return head;
}
Node* rest=reverse_node(head->next);
head->next->next=head;
head->next=NULL;
return rest;
  
}
bool paindrom(Node* head)
{   Node*l1=head;
bool reslut=true;
    Node*mid=midpointer(head);
    Node*l2=mid->next;
    l2=reverse_node(l2);
    mid->next=NULL;
    while(l1!=NULL&&l1!=NULL)
    {
        if(l1->data!=l2->data){
            reslut=false;
        }
        l1=l1->next;
        l2=l2->next;


    }
    return reslut;
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
Node * head=takeinput_better();
cout<<paindrom(head);
    return 0;
}