#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define loop(i, a, n) for (int i = a; i < n; i++)
// Wrong becaue for 10 ->9->3->1===3
//                   |_> 5->4->2->1===4 ans which is wrong

int MIN_step_1(int n)
{
    if (n == 1)
    {
        return 0;
    }
    if (n % 3 == 0)
    {

        return 1 + MIN_step_1(n / 3);
    }
    else if (n % 2 == 0)
    {
        return 1 + MIN_step_1(n / 2);
    }
    else
        return 1 + MIN_step_1(n - 1);
}
//

int MIN_step_1_2(int n)
{
    if (n == 1)
    {
        return 0;
    }
    int a = INT_MAX, b = INT_MAX, c = INT_MAX;
    if (n % 3 == 0)
    {
        a = MIN_step_1(n / 3);
    }
    if (n % 2 == 0)
    {
        b = MIN_step_1(n / 2);
    }
    if (n - 1 > 0)
        c = MIN_step_1(n - 1);

    return 1 + min(a, min(b, c));
}

// Memorization method Method-2
int MIN_step_1_3(int n, int *ans) // O(n)
{
    if (n == 1)
    {
        return 0;
    }
    //Check if output already exist or not
    if (ans[n - 1] != INT_MAX)
    {
        return ans[n - 1];
    }
    // Calculate output
    int a = INT_MAX, b = INT_MAX, c = INT_MAX;
    if (n % 3 == 0)
    {
        a = MIN_step_1(n / 3);
    }
    if (n % 2 == 0)
    {
        b = MIN_step_1(n / 2);
    }
    if (n - 1 > 0)
        c = MIN_step_1(n - 1);
    //Saving in array for future use
    ans[n - 1] = 1 + min(a, min(b, c));
    return ans[n - 1];
}

int MIN_helper(int n)
{
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = INT_MAX;
    }
    return MIN_step_1_3(n, a);
}

//
int MIN_to_1_4(int n)
{
    int *a = new int[n + 1];

    for (int i = 0; i < n+1; i++)
    {
        a[i] = INT_MAX;
    }
    a[0] = INT_MAX;
    a[1] = INT_MAX;

    a[2] = 1;
    a[3] = 1;
    int x = INT_MAX, y = INT_MAX, z = INT_MAX;
    for (int i = 4; i <= n; i++)
    {
        if ( a[i - 1] != INT_MAX)
        {
            x = a[i - 1];
        }
        if (i % 2 == 0 && a[i / 2] != INT_MAX)
        {
            y = a[i / 2];
        }
        if (i % 3 == 0 && a[n / 3] != INT_MAX)
        {
            z = a[n / 3];
        }
        a[i] = 1 + min(x, min(y, z));
    }
    return a[n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int n;
    // cin >> n;
    cout << MIN_to_1_4(7);

    return 0;
}
/*INPUT: 



OUTPUT:

*/