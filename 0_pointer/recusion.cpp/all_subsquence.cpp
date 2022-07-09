#include<bits/stdc++.h>

using namespace std;
 #define ll long long


#define PB push_back
#define MP make_pair
typedef vector<int> vi;
typedef pair<int ,int> pi;
#define loop(i,a,n) for(int i=a;i<n;i++)

int subsquence(string input,string output[])
{
    if(input.empty())
    {
        output[0]="";
        return 1;

    }
    string smallerinput=input.substr(1);
    int smalloutput=subsquence(smallerinput,output);
    loop(i,0,smalloutput)
    {
        output[smalloutput+i]=input[0]+output[i];
    }
    return 2*smalloutput;

}
 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
string s;
cin>>s;
int n=pow(2,s.length());
string *output=new string[n];
int out=subsquence(s,output);
loop(i,0,out)
{
    cout<<output[i]<<endl;
}
cout<<out<<endl;
delete []output;
return 0;
}