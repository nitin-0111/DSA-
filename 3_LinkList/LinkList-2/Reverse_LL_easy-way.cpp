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





Node *reverseLLusingrec(Node *head) // O(n^2)
{
    if (head->next == NULL)
    {
        return head;
    }
    Node *smallans = reverseLLusingrec(head->next);
    Node *temp = smallans;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return (smallans);
}




pair<Node *, Node *> reverseLLusingrec_2(Node *head) //O(n)
{
    if (head->next == NULL)
    {
        return make_pair(head, head);
    }
    pair<Node *, Node *> smaller = reverseLLusingrec_2(head->next);
    smaller.second->next = head;
    head->next = NULL;

    return make_pair(smaller.first, head);
}




Node *helper_reverseLLusingrec_2(Node *head)
{
    return reverseLLusingrec_2(head).first;
}
Node *reverseLLusingrec_3(Node *head)
{
    if (head->next == NULL)
    {
        return head;
    }
    Node *smallans = reverseLLusingrec(head->next);
    //head ke next abi bhi (1 2 3 4 5 ->null) head=1 and head->next me 2 h
    head->next->next = head;
    head->next = NULL;
    return smallans;
}






int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node *head = takeinput_better();
    // head=reverseLLusingrec(head);

    // head = helper_reverseLLusingrec_2(head);
    head = reverseLLusingrec_3(head);
    print(head);
    return 0;
}