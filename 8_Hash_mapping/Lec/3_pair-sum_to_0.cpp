#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define loop(i, a, n) for (int i = a; i < n; i++)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<int, int> mp;
    int n;
    cin>>n;
    int ans=0;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (mp.count(a[i]) > 0)
        {
            mp[a[i]] += 1;
        }
        else
            mp[a[i]] = 1;
            continue;
    }
    // for(auto it=mp.begin();it!=mp.end();it++)
    // {
    //     cout<<it->first<<" : "<<it->second<<endl;
    // }
    // // auto it=mp.begin();
    for (auto it = mp.begin(); it != mp.end(); it++)
        if (it->first > 0)
        {
            
            break;
        }
        else
        {
            auto newit = mp.find(abs(it->first));
            if (newit != mp.end())
            {
                    ans+=newit->second*it->second;
            }
            else
            {
                continue;
            }
        }
        cout<<ans<<endl;
    delete []a;
    return 0;
}