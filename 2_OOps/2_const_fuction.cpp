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

    int age;

    Student(int r):rollNumber(r)  {
        
    }

    int getRollNumber()const {
        return rollNumber;
    }

};
 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
 Student s1(101);
    s1.age = 20;

    Student const s2 (s1);
    cout << s2.getRollNumber();

return 0;
}