#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define loop(i, a, n) for (int i = a; i < n; i++)
/*  n=1^2+2^2+3^2...   min terms required
  */
// memorization approch
pair<int, int> min_count(int n, int *ans)
{
    if (n == 1 || n == 0)
    {
        pair<int, int> t;
        t.second = n;
        t.first = n;
        return t;
    }
    // check if it exits
    if (ans[n] != INT_MAX)
    {
        pair<int, int> temp;
        temp.first = ans[n];
        temp.second = n;
        return temp;
    }
    int sq = sqrt(n);
    int *call = new int[sq];
    for (int i = 0; i < sq; i++)
    {
        call[i] = INT_MAX;
    }
    for (int i = 0; i < sq; i++)
    {
        int l = i + 1;
        pair<int, int> temp = min_count(n - l * l, ans);

        if ((n) == (l * l) + temp.second)
        {
            call[i] = temp.first + 1;
        }
    }
    int MIN = call[0];
    for (int i = 1; i < sq; i++)
    {
        if (MIN > call[i])
        {

            MIN = call[i];
        }
    }
    pair<int, int> t;
    t.first = MIN;
    ans[n] = MIN;
    t.second = (n);
    return t;
}
int min_helper(int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        ans[i] = INT_MAX;
    }
    ans[1] = 1;
    return min_count(n, ans).first;
}

int min_dp(int n)
{
    int **a = new int *[n + 1];
    int sq = sqrt(n);
    for (int i = 0; i < n + 1; i++)
    {
        int index = sqrt(i) + 1;
        a[i] = new int[index];
        for (int j = 0; j < index; j++)
        {
            a[i][j] = INT_MAX;
        }
    }
    a[0][0] = 0;

    a[1][0] = 1;
    a[2][0] = 2;
    for (int i = 3; i < n + 1; i++)
    {
        int sqr=sqrt(i);
        for (int j = 1; j*j <= i; j++)
        {
            a[i][j] = 1 + a[i - j * j][0];
        }
        sort(a[i], a[i] + (sqr + 1));
    }
    return a[n][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int n;
    // cin>>n;
    // cout<<min_helper(3);
    // cout<<endl;
    cout << min_dp(12);
    return 0;
}
/*INPUT: 



OUTPUT:

*/