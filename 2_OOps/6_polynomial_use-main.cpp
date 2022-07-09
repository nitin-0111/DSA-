#include<bits/stdc++.h>

using namespace std;
 #define ll long long


#define PB push_back
#define MP make_pair
typedef vector<int> vi;
typedef pair<int ,int> pi;
#define loop(i,a,n) for(int i=a;i<n;i++)



class polynomial
{
    int *degcoeff;
    int capacity;
    int nextindex;
    public:
    polynomial()
    {
        degcoeff=new int [6]{0};
       
        capacity=6;
        nextindex=0;
    }
    polynomial(int *deg,int *coeff,int n)
    {
       
        int mx=deg[n-1];
      
        while(capacity>mx)
        {
            int *temp=new int [2*capacity]{0};
          
            
            delete []degcoeff;
            degcoeff=temp;
            capacity*=2;

        }
        for(int i=0;i<n;i++){
        this->degcoeff[deg[i]]=coeff[i];
            nextindex++;
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
            while(deg<capacity){int *temp=new int [2*capacity]{0};
            
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





 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
int *deg1=new int [n];
loop(i,0,n)
{
    cin>>deg1[i];
}
int *coeff1=new int [n];
loop(i,0,n)
{
    cin>>coeff1[i];
}
polynomial p1(deg1,coeff1,n);
p1.print();
int m;
cin>>m;
int *deg2=new int [m];
int *coeff2=new int [m];
loop(i,0,m)
cin>>deg2[i];
loop(i,0,m)
{cin>>coeff2[i];}
polynomial p2(deg2,coeff2,m);
p2.print();

return 0;
}
