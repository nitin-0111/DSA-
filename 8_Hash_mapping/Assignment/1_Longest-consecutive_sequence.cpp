#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define loop(i, a, n) for (int i = a; i < n; i++)

int longest_consective(int n)
{
    int *a = new int[n];
    unordered_map<int, bool> check;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        check[a[i]] = true;
    }
    int  maxsize = 0, ct = 0, ct1 = 0, start = -1, end = -1;
    for(int i=0;i<n;i++)
    {
        if(check[a[i]])
        {
            if(check.find(a[i]-1)==check.end())
            {
                int j=a[i];
                while(check.find(j)!=check.end())
                {
                    check[j]==false;
                    j++;
                }
                if(maxsize<j-a[i])
                {
               maxsize=max(maxsize,j-a[i]);
               start=a[i];
               end=j--;


                }


            }
        }
    }
    cout<<start<<" "<<end<<endl;
    return maxsize;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cout<<longest_consective(n)<<endl;

    // for (int i = 0; i < n; i++)
    // {
    //     l:
    //     if (check[a[j]])
    //     {
    //         if (check.count(a[j] + i + 1) > 0&&(ct-i)>=0)
    //         {
    //             check[a[j] + i + 1] = false;
    //             ct++;
    //         }

    //         if (check.count(a[j] - (i + 1)) > 0&&(ct1-i)>=0)
    //         {
    //             check[a[j] - (i + 1)] = false;
    //             ct1++;
    //         }

    //         if (!check.count(a[j] + i + 1) > 0 && !check.count(a[j] - (i + 1)) > 0)
    //         {
    //             if (maxsize < ct + ct1)
    //             {
    //                 maxsize = ct + ct1+1;
    //                 start = a[j] - ct1;
    //                 end = a[j] + ct;
    //                 i=0;
    //                 j++;

    //                 ct = 0;
    //             }
    //             else
    //             {
    //                 j++;
    //                 i=0;
    //                 goto l;
    //             }
    //         }
    //     }
    //     else

    //     j++;
    //     continue;
    // }
    
    return 0;
}