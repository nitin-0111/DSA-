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

Node *swap(Node *head, int i, int j)
{
    int ct = 0;
    Node *p1, *c1, *p2, *c2;
    Node *temp = head;
    while (temp != NULL)
    {
        if (i == 0 || j == 0)
        {

            c1 = head;
            if (max(i, j) == ct)
            {
                c2 = temp;
            }

            temp = temp->next;
            ct++;
        }
        else
        {
            if (ct == i - 1)
            {
                p1 = temp;
            }
            else if (ct == j - 1)
            {
                p2 = temp;
            }
        }
        temp = temp->next;
        ct++;
    }
    if (i == 0 || j == 0)
    {
        Node *l = c1;
        c1->next = c2->next;
        l->next = c1;
        c2->next = l;
        head = c2;
    }
    else
    {
        c1 = p1->next;
        c2 = p2->next;
        p1->next = c2;
        p2->next = c1;
        c1->next = c2->next;
        c2->next = p2;
    }

    return (head);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node *head = takeinput_better();
    int i, j;
    cin >> i >> j;
    head = swap(head, i, j);
    print(head);
    return 0;
}