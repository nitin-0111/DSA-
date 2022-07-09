 
 
   #include <bits/stdc++.h>

using namespace std;
#define ll long long
#define loop(i, a, n) for (int i = a; i < n; i++)

void Sort(int pq[], int n)
{
    //Crating  inside the same array
    for (int i = 1; i < n; i++)
    {
        int childIndex = i;
        while (childIndex > 0) //    DOWN ify
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
                childIndex = parentIndex;
            }
            else
                break;
        }
    }
    //Remove elements
    int size = n;
    while (size > 1)
    {
        int temp = pq[0];
        pq[0] = pq[size - 1];
        pq[size-1]=temp;
        size--;
        int parentIndex = 0;
        while (parentIndex < size)
        {
            int childIndex_1 = 2 * parentIndex + 1;
            int childIndex_2 = 2 * parentIndex + 2;

            if (pq[parentIndex] > pq[childIndex_2] || pq[parentIndex] > pq[childIndex_1])
            {
                int minchild = min(pq[childIndex_1], pq[childIndex_2]);
                if (minchild == pq[childIndex_1])
                {
                    swap(pq[parentIndex], pq[childIndex_1]);
                    parentIndex = childIndex_1;
                }
                else
                {
                    swap(pq[parentIndex], pq[childIndex_2]);
                    parentIndex = childIndex_2;
                }
            }
            else
                break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
 int *a=new int [n];
 for(int i=0;i<n;i++)
 {
     cin>>a[i];
 }

 Sort(a,n);
 for(int i=0;i<n;i++)
 {
     cout<<a[i]<<" ";

 }
 cout<<endl;
    return 0;
}