#include<bits/stdc++.h>
using namespace std;
// #include"queue_using_array.h"
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)

template<typename T>
class queue_using_array{
    T * data;
    int size;
    int capacity;
    int nextindex;
    int firstindex;
    queue_using_array(int s)
    {
        data=new T[s];
        size=0;
        nextindex=0;
        capacity=s;
        firstindex=-1;
    }
    int getsize()
    {
        return size;
    }
    //  OLD version//
    // void enqueue(T element)
    // {
    //     if(size==capacity)
    //     {
    //         cout<<"queue full"<<endl;
    //         return;
    //     }
    //     data[nextindex]=element;
    //     nextindex=(nextindex+1)%capacity;
    //     if(firstindex==-1)
    //     {
    //         firstindex=0;
    //     }
    //     size++;
    // }
    // bool isEmpty()
    // {
    //     return size==0;
    // }

    //          NEW version
    void enqueue(T element )
    {
        if(size==capacity)
        {
            T *newData=new T[2*capacity];
            int j=0;
            for(int i=firstindex;i<capacity;i++)
            {
                newData[j]=data[i];
                j++;
            }
            for(int i=0;i<firstindex;i++)
            {
                newData[j]=data[i];
            }
            delete []data;
            data=newData;
            firstindex=0;
            nextindex=capacity;
            capacity*=2;

        }
        data[nextindex]=element;
        nextindex=(nextindex+1)%capacity;
        if(firstindex==-1)
        {
            firstindex=0;
        }
        size++;
    }
    T front()
    {
        if(isEmpty())
        {
            cout<<"queue is empty "<<endl;
            return 0;
        }
        return data[firstindex];
    }
    T dequeur()
    {
        if(isEmpty())
        {
            cout<<" Queue is empty"<<endl;
            return 0;
        }
        T ans=data[firstindex];
        firstindex=(firstindex+1)%capacity;
        size--;
        if(size==0)
        {
            firstindex=-1;
            nextindex=0;

        }
        return ans;
    }
};
 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
queue_using_array<int> s(5);
return 0;
}