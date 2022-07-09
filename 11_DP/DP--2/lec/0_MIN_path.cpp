#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define loop(i, a, n) for (int i = a; i < n; i++)
/*  MY approch--->Wrong ans(something worng in edge case)*/
int MIN_path_1(int **IN, int **ans, pair<int, int> s, pair<int, int> e)
{//base case 
    if (s.first == e.first && s.second == s.second)
    {
        return IN[e.first][e.second];
    }
    if (s.first > e.first || s.second > e.second)
    {
        return INT_MAX;
    }
    // Check if already exist or not
    if (ans[s.first][s.second] != INT_MAX)
    {
        return ans[s.first][s.second];
    }
    int a = INT_MAX, b = INT_MAX, c = INT_MAX;
    if (s.first + 1 <= e.first && s.second <= e.second)
    {
        pair<int, int> temp1 = {s.first + 1, s.second};
        a = MIN_path_1(IN, ans, temp1, e);
    }
    // else
    //     return INT_MAX;
    if (s.first <= e.first && s.second + 1 <= e.second)
    {
        pair<int, int> temp2 = {s.first, s.second + 1};
        b = MIN_path_1(IN, ans, temp2, e);
    }
    // else
    //     return INT_MAX;
    if (s.first + 1 <= e.first && s.second + 1 <= e.second)
    {
        pair<int, int> temp3 = {s.first + 1, s.second + 1};
        c = MIN_path_1(IN, ans, temp3, e);
    }
    // else
    //     return INT_MAX;
        // Save for future use
    ans[s.first][s.second] = IN[s.first][s.second] + min(a, min(b, c));
    return ans[s.first][s.second];
}
/* Helper fuction for above code*/
int helper_MInpath_1()
{
    int row, col;
    cin >> row;
    cin >> col;
    int **arr = new int *[row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col];
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
    int **ans = new int *[row];
    for (int i = 0; i < row; i++)
    {
        ans[i] = new int[col];
        for (int j = 0; j < col; j++)
        {
            ans[i][j] = INT_MAX;
        }
    }

    pair<int, int> s = {0, 0};
    pair<int, int> e = {row - 1, col - 1};
    return MIN_path_1(arr, ans, s, e);
}





/*  Brute force approch*/
int minCostPath(int **input, int m, int n, int i, int j)
{
    // Base case
    if (i == m - 1 && j == n - 1)
    {
        return input[i][j];
    }
    if (i >= m || j >= n)
    {
        return INT_MAX;
    }
    // Recursive calls
    int x = minCostPath(input, m, n, i, j + 1);
    int y = minCostPath(input, m, n, i + 1, j + 1);
    int z = minCostPath(input, m, n, i + 1, j);
    int ans = min(x, min(y, z)) + input[i][j];
    return ans;
}






/*      Memorization Method */
int MIN_Path(int **IN, int **ans, int i, int j, int m, int n)
{ //Base case
    if (i == m - 1 && j == n - 1)
    {
        return IN[i][j];
    }
    if (i >= m || j >= n)
    {
        return INT_MAX;
    }
    //check If ans already exists
    if (ans[i][j] != INT_MAX)
    {
        return ans[i][j];
    }
    int x = MIN_Path(IN, ans, i, j + 1, m, n);
    int y = MIN_Path(IN, ans, i + 1, j + 1, m, n);
    int z = MIN_Path(IN, ans, i + 1, j, m, n);
    // Save for future use
    ans[i][j] = min(x, min(y, z)) + IN[i][j];

    return ans[i][j];
}
int helper_MInPath()
{
    int row, col;
    cin >> row;
    cin >> col;
    int **arr = new int *[row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col];
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
    int **ans = new int *[row];
    for (int i = 0; i < row; i++)
    {
        ans[i] = new int[col];
        for (int j = 0; j < col; j++)
        {
            ans[i][j] = INT_MAX;
        }
    }

    return MIN_Path(arr, ans, 0, 0, row, col);
}



/* DP--approch*/
int minCostPath_DP(int **input,int m,int n)
{
    int **output=new int*[m];
    for(int i=0;i<m;i++)
    {
        output[i]=new int[n];
    }

    //fill the last cell i.e destination
    output[m-1][n-1] =input[m-1][n-1];

    //fill last row (right to left)
    for(int j=n-2;j>=0;j++)
    {
        output[m-1][j]=output[m-1][j+1]+input[m-1][j];

    }

    //Fill last colume ( bottom to top )
    for(int i=m-2;i>=0;i--)
    {
        output[i][n-1]=output[i+1][n-1]+input[i][n-1];

    }
    // Fill remaining cells
    for(int i=m-2;i>=0;i--)
    {
        for(int j=n-2;j>=0;j--)
        {
            output[i][j]=min(output[i][j+1],min(output[i+1][j+1],output[i+1][j]));
        }
    }
    return output [0][0];
}
int helper_MInPath_Dp()
{
    int row, col;
    cin >> row;
    cin >> col;
    int **arr = new int *[row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col];
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
    // int **ans = new int *[row];
    // for (int i = 0; i < row; i++)
    // {
    //     ans[i] = new int[col];
    //     for (int j = 0; j < col; j++)
    //     {
    //         ans[i][j] = INT_MAX;
    //     }
    // }

    return  minCostPath_DP(arr,row,col);
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout<<helper_MInpath_1()<<endl;
    cout << endl;

    int ans = helper_MInPath_Dp();
    cout << ans;
    return 0;
}
/*INPUT: 1:
3 4
3 4 1 2
2 1 8 9
4 7 8 1

2:
3 4
10 6 9 0
-23 8 9 90
-200 0 89 200




OUTPUT:1: 13
2:76
*/