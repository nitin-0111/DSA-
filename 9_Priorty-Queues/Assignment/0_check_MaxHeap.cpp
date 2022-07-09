#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define loop(i, a, n) for (int i = a; i < n; i++)

bool check_max(int a[], int n)
{
    bool ans = true;
    for (int i = 0; i < n; i++)
    {
        int parent = i;
        int child_1 = 2 * parent + 1;
        int child_2 = 2 * parent + 2;
        if (child_1 < n && child_2 < n)
        {
            if (a[parent] > a[child_1] && a[parent] > a[child_2])
            {
                continue;
            }
            else
            {
                ans = false;
                break;
            }
        }
        else
        break;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << check_max(a, n);
    delete[] a;
    return 0;
}