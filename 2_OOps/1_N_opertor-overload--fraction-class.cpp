#include<bits/stdc++.h>

using namespace std;
 #define ll long long


#define PB push_back
#define MP make_pair
typedef vector<int> vi;
typedef pair<int ,int> pi;
#define loop(i,a,n) for(int i=a;i<n;i++)
class fraction{
    private:
    int numerator;
    int denomerator;
    public:
    fraction(int numerator,int denomerator)
    {
        this->numerator=numerator;
        this->denomerator=denomerator;
    }
    void print (){
        cout <<numerator<<"/"<<denomerator<<endl;

    }
    void simplify(){
        int gcd=1;
        int j=min(numerator,denomerator);
        for(int i=1;i<=j;i++)
        {
            if(numerator%i==0&&denomerator%i==0)
            {
                gcd=i;
            }
        }
        numerator/=gcd;
        denomerator/=gcd;
    }
//     fraction add(fraction f2){
//         int lcm=denomerator*f2.denomerator;
//         int num=numerator*f2.denomerator+f2.numerator*denomerator;
//         fraction fnew(num,lcm);

//         fnew.simplify();
//  return fnew;
//     }
    fraction operator+(fraction f2){
        int lcm=denomerator*f2.denomerator;
        int num=numerator*f2.denomerator+f2.numerator*denomerator;
        fraction fnew(num,lcm);

        fnew.simplify();
 return fnew;
    }
    bool operator==(fraction f2)
    {
        return( numerator==f2.numerator&&denomerator==f2.denomerator);
    }
    //per--incerment ++i
    fraction& operator++ ()
    {
        numerator=numerator+denomerator;
        simplify();
        return *this;
    }
    //post--incerment i++

    /* 
    fraction& operator++ ()   ->pre increment

    fraction operator++(int ) -> post inscrement 
                        |
                        v
          ++f1,,      f1++  to distingus b/w them               
    
     */
    fraction operator++(int )
    {
        fraction fnew(numerator,denomerator);
        numerator+=denomerator;
        return(fnew);
    }
    //+=   i+=j-->i=i+j;
    /*
       (fraction const & f2)  ->  & to avoid copy , const -> to avoid illgal changes

       fraction &  ->   fraction for nesting purpose, & to avoid temp buffer by main in nesting case
    */
    fraction & operator+= (fraction const & f2)
    {
         int d=this->denomerator*f2.denomerator;
         int n=this->numerator*f2.denomerator+f2.numerator*this->denomerator;
         numerator=n;
         denomerator=d;
        simplify();
        return *this;
    }
    
    // fraction operator++ ()
    // {
    //     numerator=numerator+denomerator;
    //     simplify();
    //     return *this;
    // }
};

 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
fraction f1(10,2);
fraction  f2(15,4);
(f1+=f2)+=f2;
f1.print();


// // ++f1;
// f1.print();
// ++(++f1);
// f1.print();
// fraction f3=++(++f1);
// f3.print();
/*fraction f2(15,4);
fraction f3=f1+f2;
f3.print();
f3==f2?cout<<"equal":cout<<"not equal"<<endl;*/
return 0;
}