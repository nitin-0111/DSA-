#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define PB push_back
#define MP make_pair
typedef vector<int> vi;
typedef pair<int, int> pi;
#define loop(i, a, n) for (int i = a; i < n; i++)

int lastindex(int a[], int n, int x)
{
    if (n == 0)
    {
        return -1;
    }
    int ans = lastindex(a + 1, n - 1, x);
    if (ans == -1)
    {
        if (a[0] == x)
        {
            return 0;
        }
        else
        return (ans);
    }
    else
    {
        return(ans+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int *a = new int[n];
    loop(i, 0, n)
    {
        cin >> a[i];
    }
    int x;
    cin >> x;
    cout << lastindex(a, n, x);
    delete []a;
    return 0;
}