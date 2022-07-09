#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define loop(i, a, n) for (int i = a; i < n; i++)
/*Brute force*/
int LCS(string s, string t)
{
    // Base case
    if (s.size() == 0 || t.size() == 0)
    {
        return 0;
    }
    //Recursive Calls
    if (s[0] == t[0])
    {
        return 1 + LCS(s.substr(1), t.substr(1));
    }
    else
    {
        int a = LCS(s.substr(1), t);
        int b = LCS(s, t.substr(1));
        // not required because it get cover under if(s[0]==t[0]) case
        //int c=LCS(s.substr(1),t.substr(1));

        return max(a, b);
    }
}

/*Memorization approch
    O(M*N)
    space O(M*N)--bcz a matrix array of m*n is created*/
int LCS_mem(int **ans, string s, string t)
{
    // Base case
    if (s.size() == 0 || t.size() == 0)
    {
        return 0;
    }
    //Recursive Calls
    if (ans[s.size()][t.size()] != -1)
    {
        return ans[s.size()][t.size()];
    }
    if (s[0] == t[0])
    { // saving for future use
        ans[s.size()][t.size()] = 1 + LCS_mem(ans, s.substr(1), t.substr(1));
        return ans[s.size()][t.size()];
    }
    else
    {
        int a = LCS_mem(ans, s.substr(1), t);
        int b = LCS_mem(ans, s, t.substr(1));
        // not required because it get cover under if(s[0]==t[0]) case
        //int c=LCS(s.substr(1),t.substr(1));
        // saving for future use
        ans[s.size()][t.size()] = max(a, b);
        return ans[s.size()][t.size()];
    }
}
int Helper(string s, string t)
{
    int **ans = new int *[s.size() + 1];
    for (int i = 0; i < s.size() + 1; i++)
    {
        ans[i] = new int[t.size() + 1];
        for (int j = 0; j < t.size() + 1; j++)
        {
            ans[i][j] = -1;
        }
    }
    return LCS_mem(ans, s, t);
}

/*DP- approch */
int Lcs_DP(string s, string t)
{
    int m = s.size(), n = t.size();
    int **ans = new int *[m + 1];
    for (int i = 0; i < m + 1; i++)
    {
        ans[i] = new int[n + 1];
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                ans[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s[m-i] == t[n-j])// agar koi error aata h to {"if(s[m-i]==t[n-j])"}
            {
                ans[i][j] = 1 + ans[i - 1][j - 1];
            }
            else
            {
                int x = ans[i][j - 1];
                int y = ans[i - 1][j];
                int z = ans[i - 1][j - 1];
                ans[i][j] = max(x, max(y, z));
            }
        }
    }
    return ans[m][n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    string t;
    cin >> s >> t;

    cout << LCS(s, t) << endl;
    cout << Helper(s, t) << endl;
    cout << Lcs_DP(s, t) << endl;

    return 0;
}
/*INPUT: 



OUTPUT:

*/