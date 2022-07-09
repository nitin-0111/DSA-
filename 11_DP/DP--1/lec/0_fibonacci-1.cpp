#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define loop(i, a, n) for (int i = a; i < n; i++)

// old recursive way
int fibo(int n)
{
    if (n <= 1)
    {             //O(2^n)
        return n; //because we are not save and repiting the task many a times
    }
    int a = fibo(n - 1); // 1.<---- Brute force
    int b = fibo(n - 2);
    return a + b;
}

/*  MEMORIZATION    Approch (Recrsive)  top-->down
     In this we are calling from top to
     down and storing the ans
*/

int fibo_helper(int n, int *ans)//O(n)  By only saving prevoius calculated fibonacci no. in ans arry 
{                               // time complecity reduced from O(2^n)-->O(n)
    if (n <= 1)
    {                               //2.<-----Memorization (Top--down)    
        return n;
    }
    // check if output already exists or not if exist the 
    //return ans directly
    if (ans[n] != -1)
    {
        return ans[n];
    }
    int a=fibo_helper(n-1,ans);
    int b=fibo_helper(n-2,ans);
    // Save the output for future use
    ans[n]=a+b;
    //Return the final output 
    return ans[n];

}
int fibo_2(int n)
{
    int *ans = new int[n + 1];
    for(int i=0;i<n+1;i++)
    {
        ans[i]=-1;
    }
    return fibo_helper(n, ans);
}

/* Dynamic Programing (Bottom -- up)
    (Iterative hota h)
*/
int fibo_3(int n)           //O(n)
{
    int *ans=new int[n+1];      //basic case ko fill (means bottom case ko)
    ans[0]=0;
    ans[1]=1;
    for(int i=2;i<n+1;i++)
    {
        ans[i]=ans[i-1]+ans[i-2];
    }
    return ans[n];
}
/* Out of 3 Dp is best  because 2--arroch take space in stack  for recursive calls
*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
cout<<fibo_2(3);
    return 0;
}