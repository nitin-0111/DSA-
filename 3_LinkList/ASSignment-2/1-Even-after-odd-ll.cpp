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
Node *even_after_odd(Node *head)
{
    Node *oh = NULL;

    Node *ot = NULL;
    Node *eh = NULL;
    Node *et = NULL;
    
    while (head != NULL)
    {
        if (head->data % 2 == 0)
        {
            if (eh == NULL)
            {
                eh = head;
                et = head;
            }
            else
                et->next = head;
            et = head;
        }
        else
        {
            if (oh == NULL)

            {
                oh = head;
                ot = head;
            }

            else
            {
                ot->next = head;
                ot = head;
            }
        }
        head = head->next;
    }
head=oh;
ot->next=eh;
et->next=NULL;
return(head);
}

    int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
Node* head=takeinput_better();
head=even_after_odd(head);
print(head);
    return 0;
}