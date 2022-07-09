#include<bits/stdc++.h>

using namespace std;
 #define ll long long


#define PB push_back
#define MP make_pair
typedef vector<int> vi;
typedef pair<int ,int> pi;
#define loop(i,a,n) for(int i=a;i<n;i++)


map<int, string> keypad{{2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};
void print_key(int n,string output)
{
    if(n==0)
    {
        cout<<output<<endl;
        return;
    }
    int ld=n%10;
    int rem=n/10;
    print_key(rem,)
} 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);

return 0;
}