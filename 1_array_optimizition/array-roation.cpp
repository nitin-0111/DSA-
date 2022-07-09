#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define PB push_back
#define MP make_pair
typedef vector<int> vi;
typedef pair<int, int> pi;
#define loop(i, a, n) for (int i = a; i < n; i++)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int d;
    cin >> d;
    int *temp = new int[d];
    int a[6]{5, 4, 7, 9, 0, 1};
    int n = 6;
    loop(i, 0, n)
    {
        cout << a[i] << " ";
    }
    cout<<endl;
    loop(i, 0, d)
    {
        temp[i] = a[i];
    }
    int j = 0;
    loop(i, 0, n - d)
    {
        a[i] = a[i + d];
    }
    loop(i, n - d, n)
    {
        a[i] = temp[j];
        j++;
    }
    loop(i, 0, n)
    {
        cout << a[i] << " ";
    }
delete []temp;
    return 0;
}