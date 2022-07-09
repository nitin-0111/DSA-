#include<bits/stdc++.h>

using namespace std;
 #define ll long long


#define PB push_back
#define MP make_pair
typedef vector<int> vi;
typedef pair<int ,int> pi;
#define loop(i,a,n) for(int i=a;i<n;i++)

class student{
    static int totalstudent;
    public:
    int roll;
    int age;
    // static int totalstudent;

    //want to increase on every obj. creation then
    student()
    {//bcz whenever we create a obj. deafult constror is called
        totalstudent++;
    }

    static int getTotalstudent()
    {
      return totalstudent;
    }
};
//if  we want to initialise static variable 
int student:: totalstudent=20;
 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
// cout<<student::totalstudent;
student s1,s2;

cout<<student::getTotalstudent<<endl;
return 0;
}