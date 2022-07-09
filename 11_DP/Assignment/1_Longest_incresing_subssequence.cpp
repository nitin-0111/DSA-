#include<bits/stdc++.h>

using namespace std;


 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)

int LIS(int *input,int n)
{
    if(n<=0)
    {
        return 0;
    }
    static int min=INT_MIN;//
    if(input[0]<min)
    {
        return LIS(input+1,n-1);//if previous element selected in subsquence and current element is smaller than that left if and move forward
    }
    else
    {
        min=input[0];
        int a=1+LIS(input+1,n-1);
        int b=LIS(input+1,n-1);
        return max(a,b);
    }
}
/*memorization approch
*/
int LIS_me(int *input,int n,int *ans)
{
    if(n<=0)
    {
        return 0;
    }
    if(ans[n]!=0)
    {
        return ans[n];
    }
    static int min=INT_MIN;
    if(input[0]<min)
    {
        ans[n]=LIS(input+1,n-1);
        return ans[n];
    }
    else
    {
        min=input[0];
        int a=1+LIS(input+1,n-1);
        int b=LIS(input+1,n-1);
        ans[n]=max(a,b);
        return ans[n];
    }


}
int helper(int *input,int n)
{
    int *ans=new int [n+1];
    for(int i=0;i<=n;i++)
    {
        ans[i]=0;
    }
    return LIS_me(input,n,ans);
}




/* DP*/
int LIS_Dp(int * input,int n)
{
    int * output=new int [n];
    output[0]=1;
    for(int i=1;i<n;i++)
    {
        output[i]=1;
        for(int j=i-1;j>=0;j--)
        {
            if(input[j]>input[i])
            {
                continue;
            }
            int possibleAns=output[i]+1;
            if(output[i]<possibleAns)
            {
                output[i]=possibleAns;
            }
        }
    }
    int max=0;
    for(int i=0;i<n;i++)
    {
        if(max<output[i])
        {
            max=output[i];
        }
    }
    delete []output;
    return max;
}

 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
int*input=new int[n];
for(int i=0;i<n;i++)
{
    cin>>input[i];
}
cout<<LIS(input,n)<<endl;
cout<<helper(input,n)<<endl;
cout<<LIS_Dp(input,n)<<endl;
return 0;}
 /*INPUT: 



OUTPUT:

*/