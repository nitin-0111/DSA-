#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define loop(i, a, n) for (int i = a; i < n; i++)

/*Brute force approch */
int EditDistance(string s, string t)
{
    //Base case
    if (s.size() == 0 || t.size() == 0)
    {
        return 0;
    }
    int ans;
    if (s[0] == t[0])
    {
        ans = EditDistance(s.substr(1), t.substr(1));
    }
    else
    {
        if (s.size() > t.size())
        {
            ans = 1 + EditDistance(s.substr(1), t);
        }

        else if (s.size() < t.size())
        {
            ans = 1 + EditDistance(s, t.substr(1));
        }
        else
            ans = 1 + EditDistance(s.substr(1), t.substr(1));
    }
    return ans;
}

/* video way by hints my guess   "Brute force"*/
int EditDistance_1(string s, string t)
{
    if (t.size() == 0 || s.size() == 0)
    {
        return max(s.size(),t.size());
    }
    // else if (t.size() == 0 || s.size() == 0)
    // {
    //     // if (t.size() == 0)
    //     // {
    //     //     return s.size();
    //     // }
    //     // else
    //     //     return t.size();
    //     return INT_MAX;
    // }
    int ans;
    if (s[0] == t[0])
    {
        ans = EditDistance_1(s.substr(1), t.substr(1));
    }
    else
    {
        int a = EditDistance_1(s.substr(1), t);
        int b = EditDistance_1(s, t.substr(1));
        int c = EditDistance_1(s.substr(1), t.substr(1));
        ans = min(a, min(b, c)) + 1;
    }
    return ans;
}

/* Memorization approch */
int EditDistance_mem(int **ans, string s, string t)
{
    if (s.size() == 0 || t.size() == 0)
    {
         return max(s.size(),t.size());
    }
    // else if (t.size() == 0 || s.size() == 0)
    // {
    //     // if (t.size() == 0)
    //     // {
    //     //     return s.size();
    //     // }
    //     // else
    //     //     return t.size();
    //     return INT_MAX;
    // }
    int m = s.size(), n = t.size();
    if (ans[m][n] != -1)
    {
        return ans[m][n];
    }
    int temp;
    if (s[0] == t[0])
    {
        temp = EditDistance_mem(ans, s.substr(1), t.substr(1));
    }
    else
    {
        int a = EditDistance_mem(ans, s.substr(1), t);
        int b = EditDistance_mem(ans, s, t.substr(1));
        int c = EditDistance_mem(ans, s.substr(1), t.substr(1));
        temp = min(a, min(b, c)) + 1;
    }
    // saving for future use
    ans[m][n] = temp;
    return ans[m][n];
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
    return EditDistance_mem(ans, s, t);
}

/* Dp-approch*/
int EditDistance_Dp(string s, string t)
{
    int m = s.size(), n = t.size();
    int **ans = new int *[m + 1];
    for (int i = 0; i < m + 1; i++)
    {
        ans[i] = new int[n + 1];
        
    }
    // Fill 1st row
    for(int j=0;j<=n;j++)
    {
        ans[0][j]=j;
    }
    // Fill 1st col
    for(int i=1;i<=m;i++)
    {
        ans[i][0]=i;
    }
    ans[0][0] = 0;
    for(int i=1;i<m+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(s[m-i]==t[n-j])
            {
                ans[i][j]=ans[i-1][j-1];
            }
            else
            {
                int a=ans[i][j-1];
                int b=ans[i-1][j];
                int c=ans[i-1][j-1];
                ans[i][j]=min(a,min(b,c))+1;
            }
        }
    }
    return ans[m][n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t;
    cin >> s >> t;
    // cout << EditDistance(s, t) << endl;
    // cout << Helper(s, t) << endl;
    cout<<EditDistance_Dp(s,t)<<endl;
    // cout << EditDistance_1(s, t) << endl;

    return 0;
}
/*INPUT: 
1:
ab
acb

2:
abc
cab

3:
zxcb
aecb
4:
abcdfabcdfabcdfabcdfabcdfabcdfabcdfabcdfabcdfabcdfabcdf
afdfafdafdafdsfd

OUTPUT:

*/