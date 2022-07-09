#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define loop(i, a, n) for (int i = a; i < n; i++)

/* MY approch  */
// int KNAP_1(int Win[], int Vin[], int W, int n)
// {
//     if (W <= 0)
//     {
//         return 0;
//     }

//    static int ans=0;
//     for (int i = 0; i < n; i++)
//     {
//         if (Win[i] <= W)
//         {
//             ans = max(ans,max(Vin[i] + KNAP_1(Win+1, Vin+1, (W - Win[i]), n-1),KNAP_1(Win+1,Vin+1,W,n-1)));
//         }

//     }
   

//     return ans;
// }
// int KNAP_1(int Win[], int Vin[], int W, int n)
// {
//     if (W <= 0)
//     {
//         return 0;
//     }
//     static int *ans = new int[n];
//     for (int i = 0; i < n; i++)
//     {
//         ans[i] = INT_MIN;
//     }
//     int i=0;

//     int a=  Vin[i] + KNAP(Win, Vin, (W - Win[i]), n);
//     int b=
// }

/* Brute force approch */
int KNAP(int *Weight, int *value, int MAXweight, int n)
{
    // Base
    if (n == 0 || MAXweight == 0)
    {
        return 0;
    }
    if (MAXweight < Weight[0])
    {
        return KNAP(Weight + 1, value + 1, MAXweight, n - 1);
    }
    // Two recursive call
    int a = KNAP(Weight + 1, value + 1, MAXweight - Weight[0], n - 1) + value[0];// including a value   
    int b = KNAP(Weight + 1, value + 1, MAXweight, n - 1);// excluding a value

    return max(a, b);
}

/*Memorization approch*/
int KNAP_MEM(int *weight, int *value, int Maxweight, int n, int *ans)
{
    //Base case
    if (n == 0 || Maxweight == 0)
    {
        return 0;
    }
    //check if already exit
    if (ans[Maxweight] != -1)
    {
        return ans[Maxweight];
    }
    // case for check for overflow of knapsack
    if (Maxweight < weight[0])
    {
        ans[Maxweight] = KNAP(weight + 1, value + 1, Maxweight, n - 1);
        return ans[Maxweight];
    }
    // Two recursive call
    int a = KNAP(weight + 1, value + 1, Maxweight - weight[0], n - 1) + value[0];
    int b = KNAP(weight + 1, value + 1, Maxweight, n - 1);
    //saving for future use
    ans[Maxweight] = max(a, b);
    return ans[Maxweight];
}
int helper_mem(int *weight, int *value, int Maxweight, int n)
{
    int *ans = new int[Maxweight + 1];
    for (int i = 0; i <= Maxweight; i++)
    {
        ans[i] = -1;
    }
    return KNAP_MEM(weight, value, Maxweight, n, ans);
}

int KNAP_DP(int *weight, int *value, int Maxweight, int n)
{
    int **ans = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        ans[i]=new int [Maxweight+1];
    }

    for (int i = 0; i <= n; i++)
    {
        for(int j=0;j<=Maxweight;j++) 
        {
            if(i==0||j==0)
            {
                ans[i][j]=0;
            }
            else if(weight[i-1]<=j)
            {
                ans[i][j]=max(value[i-1]+ans[i-1][j-weight[i-1]],ans[i-1][j]);
            }
            else
            ans[i][j]=ans[i-1][j];
        }
    }
    return ans[n][Maxweight];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int *W_input = new int[n];
    int *v_input = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> W_input[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v_input[i];
    }
    int W_of_knapsack;
    cin >> W_of_knapsack;
    // cout<<KNAP_1(W_input,v_input,W_of_knapsack,n)<<endl;
    cout << KNAP(W_input, v_input, W_of_knapsack, n) << endl;// brute force
    cout << helper_mem(W_input, v_input, W_of_knapsack, n) << endl;// memorization
    cout<<KNAP_DP(W_input, v_input, W_of_knapsack, n);// dP

    return 0;
}
/*INPUT: 



OUTPUT:

*/