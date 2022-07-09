using namespace std;
class DyanamicArray{
    int *data;
    int nextindex;
    int capacity;
    public:
    DyanamicArray()
    {
        data=new int [5];
        nextindex=0;
        capacity=5;
    }
    //for Deep copy
    DyanamicArray(DyanamicArray const &d)
    {
        //this->data=d.data;//Shallo copy
        //Deep copy
        this->data=new int [d.capacity];
        for(int i=0;i<d.nextindex;i++)
        {
            this->data[i]=d.data[i];
        }
        this->nextindex=d.nextindex;
        this->capacity=d.capacity;
    }
    void operator=(DyanamicArray const& d)
    {
        // Assignment operator overloding
        this->data=new int [d.capacity];
        for(int i=0;i<d.nextindex;i++)
        {
            this->data[i]=d.data[i];
        }
        this->nextindex=d.nextindex;
        this->capacity=d.capacity;
    }
    void add(int element )
    {
        if(nextindex==capacity)
        {
            int *temp=new int [2*capacity];
            for(int i=0;i<capacity;i++)
            {
                temp[i]=data[i];
            }
            delete []data;
            data=temp;
            capacity*=2;
        }
        else 
        {
            data[nextindex]=element;
            nextindex++;
        }
    }
    void print()
    {
        for(int i=0;i<nextindex;i++)
        {
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
    
};