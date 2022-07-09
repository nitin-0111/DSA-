#include<bits/stdc++.h>

using namespace std;


 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)


class student{
    public:
    int roll;
    int age;
    static int totalstudent;// we can't initiallize it here 
    student(){
        totalstudent++;
    }
    int static gettotalstudent()
    {
        return totalstudent;
    }
} ;
int student::totalstudent=0;
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
student a;
student b;
student c;
student d;
cout<<d.totalstudent<<endl;//have to keep trace of last element 
// if you donot want to keep trace 
cout<<student::gettotalstudent()<<endl;
cout<<d.gettotalstudent()<<endl;

return 0;}
 /*INPUT: 



OUTPUT:

*/