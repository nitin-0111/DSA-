template<typename T>
class Node{
    public:
    T data;
    Node<T>*next;
    Node(T data)
    {
        this->data=data;
        next=NULL;
    }

};
template<typename T>
class QueueLL{
    Node<T>* head;
    Node<T>* tail;
    int size;
    public:
    QueueLL()
    {
        head=NULL;
        tail=NULL;
        size=0;
    }
    int getsize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size==0;
    }
    void enqueue(T element)
    {
        Node<T>* newnode=new Node<T>(element);
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        size++;
    }
    T front(){
        return(head->data);

    }
    T dequeue(){
        T ans =head->data;
        Node<T>*temp=head;
        head=head->next;
        delete temp; 
        size--;
        return ans;

    }

};