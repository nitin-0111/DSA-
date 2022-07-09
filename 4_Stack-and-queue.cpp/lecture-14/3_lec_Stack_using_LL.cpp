#include<bits/stdc++.h>

using namespace std;
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)

/* Stack using Linklist*/




// creating LL to use in stack
template<typename T>
class Node
{
public:
    Node<T> *next;  //***node<T>
    T data;
    Node(T d)
    {
        data = d;
        next = NULL;
    }
};




template<typename T>///har bar template mention kar na pdaga
class Stack{
    Node<T>* head;
    int size;
    public:
    Stack()
    {
        head=NULL;
        size=0;
    }

    // I think adding in front of LL
    void push(T d)
    {
        Node<T>* newnode=new Node<T>(d);
        size++;
        
        newnode->next=head;
        head=newnode;
    }
T top()
    {
        if(size==0)
        {
        return 0;
            
        }
        return head->data;
    }
    T pop()
    {
        if(size>0)
        {
            size--;
          T ans=head->data;
          Node<T>*temp=head;

            head=head->next;
            delete temp;
            return ans;
        }
        else
        cout<<" stack is empty"<<endl;
        return 0;
    }

 int getsize()
 {
     return size;
 }
 bool isempty()
 {
     if(size==0)
     {
         return true;
     }
     else
     return false;
 }

};

 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
Stack<int> p1;
p1.push(10);
p1.push(209);
cout<<p1.top()<<" "<<endl;
cout<<p1.getsize()<<endl;
cout<<p1.pop()<<" "<<endl;
cout<<p1.getsize()<<endl;
cout<<p1.top()<<" "<<endl;


return 0;
}