#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define loop(i, a, n) for (int i = a; i < n; i++)
class triplet
{
public:
    int element;
    int row;
    int col;
};
class comp
{
    public:
bool operator()(triplet a,triplet b)
{
    int x=a.element;
    int y=b.element;
    return x>y;
}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin >> k;
    int m = 0;
    int **a = new int *[k];
    int *no_array = new int[k];
    for (int i = 0; i < k; i++)
    {
        cin >> no_array[i];
        m += no_array[i];
        a[i] = new int[no_array[i]];
        for (int j = 0; j < no_array[i]; j++)
        {
            cin >> a[i][j];
        }
    }
    int *finalarray = new int[m];
    priority_queue<triplet, vector<triplet>, comp> p;
    for (int i = 0; i < k; i++)
    {
        triplet temp;
        temp.element = a[i][1];
        temp.row = i;
        temp.col = 1;
        p.push(temp);
    }

    for (int i = 0; i < m - k; i++)
    {
        triplet temp = p.top();
        p.pop();
        finalarray[i] = temp.element;
        int row = temp.row;
        int col = temp.col;
        col++;
        if (row >= 0 || row < k)
        {
            if (col >= 0 || col < no_array[row])
            {
                triplet in;
                in.row = row;
                in.col = col;
                in.element = a[row][col];
                p.push(in);
            }
            else if ((row - 1) >= 0 || (row - 1) < k && col >= 0 || col < no_array[row - 1])
            {
                triplet in;
                in.row = row - 1;
                in.col = col;
                in.element = a[row][col];
                p.push(in);
            }
            else if ((row + 1) >= 0 || (row + 1) < k && col >= 0 || col < no_array[row + 1])
            {
                triplet in;
                in.row = row + 1;
                in.col = col;
                in.element = a[row][col];
                p.push(in);
            }
            else
                break;
        }
    }
    for(int i=m-k;i<m;i++)
    {
        triplet temp=p.top();
        p.pop();
        finalarray[i]=temp.element;
    }
    for(int i=0;i<m;i++)
    {
        cout<<finalarray[i]<<" ";
    }
    cout<<endl;

    for (int i = 0; i < k; i++)
    {
        delete[] a[i];
    }
    delete[] a;
    delete[] no_array;
    delete[] finalarray;
    return 0;
}