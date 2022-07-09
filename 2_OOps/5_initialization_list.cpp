#include<bits/stdc++.h>

using namespace std;
 #define ll long long


#define PB push_back
#define MP make_pair
typedef vector<int> vi;
typedef pair<int ,int> pi;
#define loop(i,a,n) for(int i=a;i<n;i++)

class Student {
    int rollNumber;

    public :

    int const age;
    int &x;


    Student(int r,int age=0):rollNumber(r),age(age),x(this->rollNumber)  {
        
    }

   
};
 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
 Student s1(101);
  

   
return 0;
}