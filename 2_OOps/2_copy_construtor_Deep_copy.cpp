#include<bits/stdc++.h>

using namespace std;
 #define ll long long


#define PB push_back
#define MP make_pair
typedef vector<int> vi;
typedef pair<int ,int> pi;
#define loop(i,a,n) for(int i=a;i<n;i++)

class student {
    int age;
    public:
    char *name;
    student(int age,char *name)
    {
        //Deep copy
        this->age=age;
        this->name=new char [strlen(name)+1];
        strcpy(this->name,name);

    }
//Copy Constructor
student(student const &s)
{
    //Deep copy
 this->age=s.age;
    this->name=new char [strlen(s.name)+1];
    strcpy(this->name,s.name);
}
void display()
{
    cout<<name<<" "<<age<<endl;
}
};
 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
char name[]="nitin";
student s(12,name);
student s2(s);
s2.name[0]='m';
s.display();
s2.display();
return 0;
}