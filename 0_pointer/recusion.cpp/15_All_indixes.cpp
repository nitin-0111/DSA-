#include<bits/stdc++.h>

using namespace std;
 #define ll long long


#define PB push_back
#define MP make_pair
typedef vector<int> vi;
typedef pair<int ,int> pi;
#define loop(i,a,n) for(int i=a;i<n;i++)

void displayoutput(int o[],int n)
{
    loop(i,0,n)
    cout<<o[i]<<" ";
}
int allindex(int a[],int n,int x,int ( *output))
{
    if(n==0)
    {
        return 0;
    }
    int ans =allindex(a+1,n-1,x,output);
    if(a[0]==x)
    {
        if(ans!=0)
        {
            loop(i,0,ans)
            {
                output[i]+=1;
            }
            for(int i=ans-1;i>=0;i--)
            {
                output[i+1]=output[i];
            }
            output[0]=0;
            ans++;
        }
        else{
            output[0]=0;
            ans++;
        }
    
    }
    else{
        loop(i,0,ans)
        {
            output[i]+=1;
        }
    }
   
    return ans;
} 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
int *a=new int [n];
int *output=new int [n];
loop(i,0,n)
{
    cin>>a[i];
}
int x;
cin>>x;
int ans=allindex(a,n,x,output);
cout<<ans<<endl;
loop(i,0,ans)
cout<<output[i]<<" ";


return 0;
}