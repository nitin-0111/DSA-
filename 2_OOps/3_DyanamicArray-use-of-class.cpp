#include<bits/stdc++.h>

using namespace std;
 #define ll long long
#include"DyanamicArray-class.cpp"

#define PB push_back
#define MP make_pair
typedef vector<int> vi;
typedef pair<int ,int> pi;
#define loop(i,a,n) for(int i=a;i<n;i++)


 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
DyanamicArray d1;
d1.add(10);
d1.add(20);
d1.add(30);
d1.add(40);
d1.add(50);
d1.add(60);
d1.print();

DyanamicArray d2(d1);

return 0;
}