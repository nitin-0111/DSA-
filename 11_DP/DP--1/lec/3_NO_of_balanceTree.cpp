#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define loop(i, a, n) for (ll i = a; i < n; i++)
/* Worng approch  */
// ll  NO_of_balancedTree(ll h)
// {
//     ll  no_of_nodesAt_height_h;
//     no_of_nodesAt_height_h=pow(2,h-1);
//     ll no_of_NOde=no_of_nodesAt_height_h% modular;
//     ll  NO_of_tree=pow(2,no_of_NOde)-1;
//     NO_of_tree=NO_of_tree%modular;
//     return NO_of_tree;

// }
/* Recursive approch
    Memorization approch */
ll NOof_balancedTree(ll h, ll *ans)
{
    ll m = pow(10, 9) + 7;
    if (h == 1)
    {
        return 1;
    }
    if (ans[h] != -1)
    {
        return ans[h];
    }
    ll a = -1, b = -1;
    if (h - 2 > 0)
    {
        a = NOof_balancedTree(h - 1, ans)%m;
        b = NOof_balancedTree(h - 2, ans)%m;
        /*no. possible case are 
            h-1   h-1
            h-1   h-2
            h-2   h-1

            a=h-1  b=h-2
            so ans  =a*a+a*b +b*a  
        */

        ans[h] = (a%m * a%m + (2 %m* b%m * a%m)%m)%m;
    }
    return ans[h];
}
ll noOFTree(ll h)
{
    ll *ans = new ll[h + 1];
    for(ll i=0;i<h+1;i++)
    {
        ans[i]=-1;
    }
    ans[1] = 1;
    ans[2] = 3;
    return NOof_balancedTree(h, ans);
}


// similar like fabonacci
/*Dp arroch
*/
int No_of_Tree(int h)
{
    int MODU=(int)(pow(10,9)+7);
    int *ans=new int[h+1];
    for(int i=0;i<h+1;i++)
    {
        ans[i]=-1;
    }
    ans[0]=1;
    ans[1]=1;
    ans[2]=3;
    for(int i=3;i<h+1;i++)
    {
        int x=ans[i-1];
        int y=ans[i-2];
        int temp1=(int)((((ll)(x)%MODU)*(x%MODU))%MODU);
        int temp2=(int)((2*(ll)(x)%MODU*y%MODU)%MODU);
        ans[i]=temp1+temp2;


    }
    return ans[h];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll h;
    cin >> h;
    cout << noOFTree(h);

    return 0;
}
/*INPUT: 



OUTPUT:

*/