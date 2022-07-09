#include<bits/stdc++.h>

using namespace std;
#include"BinarysearchTree.h"
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)


 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
BST b;
b.insert(10);
b.insert(5);
b.insert(20);
b.insert(7);
b.insert(1);
b.insert(15);
b.insert(16);
b.insert(17);
b.print();
cout<<endl;

b.deleteData(10);
b.print();


return 0;
}