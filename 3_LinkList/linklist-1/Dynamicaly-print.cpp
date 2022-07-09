#include<bits/stdc++.h>

using namespace std;
 #define ll long long
#include "Linklist-class-1.cpp"

// #define PB push_back
// #define MP make_pair

// typedef pair<int ,int> pi;
// #define loop(i,a,n) for(int i=a;i<n;i++)


 void print( Node *head)
 {
     Node*temp=head;
     while(temp!=NULL){
         cout<<temp->data<<" ";
         temp=temp->next;
     }
     cout<<endl;
 }
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
Node *n3=new Node(10);
Node *head=n3;
Node *n4=new Node(20);
n3->next=n4;
print(head);
delete n3;
delete n4;
return 0;
}