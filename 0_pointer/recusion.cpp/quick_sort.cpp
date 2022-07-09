#include<bits/stdc++.h>

using namespace std;
 #define ll long long


#define PB push_back
#define MP make_pair
typedef vector<int> vi;
typedef pair<int ,int> pi;
#define loop(i,a,n) for(int i=a;i=n;i++)

int parition(int a[],int si,int en)
{
    int ct=0,x=a[0];
    for(int i=si;i<=en;i++){
    if(a[i]<=x)ct++;}
     
    // ct counting no smaller element then pivot
     swap(a[0],a[si+ct]);// swapping pivot to its correct position
     int i=si,j=en;
     while(i!=si+ct||j!=si+ct)
     {
         if(a[i]<=x)i++;
         else if(a[j]>x)j--;
         else
         swap(a[i],a[j]);
         i++; j--;
     }
     return (si+ct);

}
void quick_sort(int a[],int si,int en)
{
    if(si>=en)return;
    int pi= parition(a,si,en);
    
    quick_sort(a,si,pi-1);
    quick_sort(a,pi+1,en);
}


/* O(n*log(n))  in worst case O(n^2)   
                   that's why use random piovt
                   
                   Random piovte code*/

int ct=0;
int Partition(int a[],int l,int h)
{
    int pivot,index,i;
    index=l;
    pivot=h;
    for(i=l;i<h;i++)
    {
        if(a[i]<a[pivot])
        {
            if(i!=index)
            {
                ct++;
            }
            swap(&a[i],&a[index]);
            index++;
        }

    }
    swap(&a[pivot],&a[index]);
    return index;

}
  int RandomPartion(int a[],int l,int h)
  {
      int pvt,n,temp;
      n=rand();// taking a random no.
      pvt=l+n%(h-l+1);
      swap(&a[h],&a[pvt]);
      return Partition(a,l,h);
  }  
  void  QuickSort(int a[],int l, int h)
  {
      int Pi;
      if(l<h)
      {
          Pi=RandomPartion(a,l,h);
          QuickSort(a,l,Pi-1);
          QuickSort(a,Pi+1,h);
      }
  }


 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
int a[]{3,5,4,8,1,0,6,2};
quick_sort(a,0,7);
loop(i,0,7)
cout<<a[i]<<" ";
return 0;
}