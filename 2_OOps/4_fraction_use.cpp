#include<bits/stdc++.h>
using namespace std;
#include"fraction_class.cpp"
 #define ll long long


#define PB push_back
#define MP make_pair
typedef vector<int> vi;
typedef pair<int ,int> pi;
#define loop(i,a,n) for(int i=a;i<n;i++)


 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
fraction f1(10,2);
fraction f2(15,4);
f1.add(f2);
f1.print();
f2.print();

return 0;
}