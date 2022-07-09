#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define PB push_back
#define MP make_pair
typedef vector<int> vi;
typedef pair<int, int> pi;
#define loop(i, a, n) for (int i = a; i < n; i++)
map<int, string> keypad{{2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};
int possiblekey(int a, string output[])
{
    if (a == 0)
    {
        output[0] = "";
        return 1;
    }
    int ld = a % 10;
    int rem = a / 10;
    int smalloutput = possiblekey(rem, output);
    int times= smalloutput * keypad[ld].length();
    // if(smalloutput==0) times= keypad[ld].length();
    // else times= smalloutput * keypad[ld].length();
    loop(i, 0, smalloutput)
    {   loop(j,0,keypad[ld].length())
        output[smalloutput + i+j] = output[i] + keypad[ld][j];
    }
    return times;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string *output = new string[1000];

    int out = possiblekey(n, output);
    loop(i, 0, out)
    {
        cout << output[i] << endl;
    }
    delete []output;
    return 0;
}