#include<bits/stdc++.h>

using namespace std;
 #define ll long long


#define PB push_back
#define MP make_pair
typedef vector<int> vi;
typedef pair<int ,int> pi;
#define loop(i,a,n) for(int i=a;i<n;i++)

void  (int a[],int s,int e)
{
    int mid=(s+e)/2;
    int k=0;
int n1=mid+1;
int n2=e-mid+1;
    int l[n1];
    int r[n2];
    loop(i,s,n1)
    {
        l[i]=a[k];
        k++;
        
    }
    loop(i,mid+1,e){
        r[i]=a[k];
        k++;
    }
    int i=0;int j=0;int k=0;
    {if(l[i]>=r[j])
    {
        a[k]=r[j];
        j++;
    }
    else
    a[k]=l[i];
    i++;}

}
 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);

return 0;
}