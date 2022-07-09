class polynomial
{
    int *degcoeff;
    int capacity;
    int nextindex;
    public:
    polynomial()
    {
        degcoeff=new int [6];
        degcoeff={0};
        capacity=6;
        nextindex=0;
    }
    polynomial(int deg[],int coeff[])
    {
        int n=sizeof(deg)/sizeof(deg[0]);
        int max=deg[0];
      for(int i=0;i<n;i++)
        {
            max=max(deg[i],max);
        }
        while(capacity>max)
        {
            int *temp=new int [2*capacity];
            temp={0};
            
            delete []degcoeff;
            degcoeff=temp;
            capacity*=2;

        }
        for(int i=0;i<n;i++){
        this->degcoeff[deg[i]]=coeff[i];

        }
    }
    polynomial (polynomial const &p)
    {
        this->degcoeff=new int [p.capacity];
        for(int i=0;i<p.nextindex;i++)
        {
            this->degcoeff[i]=p.degcoeff[i];
        }
        this->nextindex=p.nextindex;
        this->capacity=p.capacity;
    }
    void operator=(polynomial const &p)
    {
        this->degcoeff=new int [p.capacity];
        for(int i=0;i<p.nextindex;i++)
        {
            this->degcoeff[i]=p.degcoeff[i];
        }
        this->nextindex=p.nextindex;
        this->capacity=p.capacity;
    }
    void print (){
        for(int i=0;i<nextindex;i++)
        {
            cout<<degcoeff[i]<<"x"<<i<<" ";
        }
        cout<<endl;
    }
    void setcoefficient(int deg,int coeff)
    {
        a:
        if(deg<capacity)
        {
            degcoeff[deg]=coeff;
        }
        else
        {
            while(deg<capacity){int *temp=new int [2*capacity];
            temp={0};
            for(int i=0;i<nextindex;i++)
            {
                temp[i]=degcoeff[i];
            }
            delete []degcoeff;
            degcoeff=temp;
            capacity*=2;}
            goto a;
        }
    }
};