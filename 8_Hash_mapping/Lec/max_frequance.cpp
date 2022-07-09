#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define loop(i, a, n) for (int i = a; i < n; i++)

// int max_fq(int a[], int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         if (fq.count(a[i]) > 0)
//             fq[a[i]] += 1;
//         else
//             fq[a[i]] = 1;
//     }
//     int max = 0;
//     for (int i = 0; i < size; i++)
//     {
//         if (fq.count(a[i]) > 0)
//         {
//             if (fq[a[i]] > max)
//             {
//                 max = fq[a[i]];
//             }
//         }
//         else
//             continue;
//     }
//     return max;
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int *a = new int[n];
    unordered_map<int, int> fq;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        fq[a[i]]++;
    }
    // unordered_map<int,int>::iterator it;
    int max=0,res=-1;
   for(auto i:fq)
   {
       if(max<i.second)
       {
           max=i.second;
           res=i.first;
       }
   }
   cout<<res<<" "<<endl;
    delete[] a;
    return 0;
}