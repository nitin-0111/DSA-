// int Solution::braces(string A) {
// }
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define loop(i, a, n) for (int i = a; i < n; i++)

unordered_set<char> operation = {'+', '-', '*', '/'};
map<char, int> bractet{{'(', 1}, {')', -1}};
int redundat_brackets(string s)
{
    stack<char> pending;
    int ct = 0;
    int ans = 0;
    int sct=0;
    for (int i = 0; i < s.length(); i++)
    {
        while (s[i] != ')')
        {
            pending.push(s[i]);
            i++;
        }
        while (pending.top() != '(')
        {
            if(count(operation.begin(),operation.end(),pending.top()))
            {
                sct+=1;
            }
            pending.pop();
            ct++;
        }
        pending.pop();
        if (ct != 0&&)
        {
            ct = 0;
            ans = 1;
        }
        else
        {
            ans = 0;
            break;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    cout << endl;
    int ans = redundat_brackets(s);
    cout << ans;
    return 0;
}