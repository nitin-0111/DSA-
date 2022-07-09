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
Node *delete_n_node(Node *head, int n, int m)
{
    Node *temp = head;
    int tc = 1, lc = 0;
    Node *t=NULL;
    while (temp != NULL)
    {
        if (tc != n)
        {
            ++tc;
            temp = temp->next;
        }
        else if(tc==n)
        {
            t=temp;
            while(lc!=m)
            {
                t=t->next;
                ++lc;
            }
            temp->next=t->next;
            temp=t->next;
            t=NULL;
            tc=1;lc=0;
        }
    }
    return(head);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
Node*head=takeinput_better();
head=delete_n_node(head,2,2);
print(head);
    return 0;
}