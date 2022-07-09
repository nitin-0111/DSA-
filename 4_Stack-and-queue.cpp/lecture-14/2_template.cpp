#include<bits/stdc++.h>

using namespace std;
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)


/* Introduction of template  */
template<typename T,typename v>
class Pair{
    T x;
    v y;
    public:
   T getx()
    {
        return x;
    }
    v gety()
    {
        return y;
    }
    void setx(T a)
    {
        x=a;
    }
    void sety(v b)
    {
        y=b;
    }
    
    
};
 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
Pair <Pair<int,int>,int>p1;
Pair<int ,int>p2;
p2.setx(10);
p2.sety(123);
p1.setx(p2);
p1.sety(12);
cout<<p1.getx().getx()<<p1.getx().gety()<<" "<<p1.gety();


return 0;
}