#include <iostream>

using namespace std;

int a[200001];
//int dd[200001][200001];
int ans[200001];

int binary_search(int* ddd, int end, int arrow, int n, int **d)
{

    if (arrow > ddd[end])
        return -1;

    int start = 1;
    int mid = 0;
    while (start <= end)
    {
        mid = (end + start)/2;
        if (arrow == ddd[mid])
            return mid;
        if (arrow < ddd[mid])
            end = mid-1;
        else
            start = mid+1;
    }
    for (int j=1;j<=n-mid+1;j++)
    {
        d[mid][j]-=arrow;
    }

    //cout << mid << endl;
    return mid-1;
}

void redo_d(int n, int **d)
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n-i+1;j++)
        {
            d[i][j] = d[i][j-1] + a[j+i-1];
            //dd[i][j] = d[i][j];
        }
}

int main()
{
    int n,q;
    cin >> n >> q;

    //int d[200001][200001];

    vector<vector<int> > d(n+1);

    for(int i=0; i<=n; ++i)
    {
        d[i] = new int[n+1];
    }
    for (int i=0;i<=n;i++)
        for (int j=0;j<=n;j++)
            d[i][j] = 0;

    for (int i=1;i<=n;i++)
        cin >> a[i];

    for (int i=1;i<=n;i++)
        for (int j=1;j<=n-i+1;j++)
        {
            d[i][j] = d[i][j-1] + a[j+i-1];
            //dd[i][j] = d[i][j];
        }


    int index = 1;
    int left = n;
    for (int i=1;i<=q;i++)
    {
        int arrow = 0;
        cin >> arrow;

        // if (arrow < d[index][1])
        // {
        //     ans[i] = left;
        //     d[index][1] -= arrow;
        //     continue;
        // }
        int root = index;
        index = binary_search(d[index], n-index+1, arrow, n, d);
        if (index == -1 || index == (n-index+1))
        {
            index = 1;
            left = n;
            ans[i] = n;
            redo_d(n, d);
        }
        else
        {
            left -= index;
            index = index + 1;
            ans[i] = left;
        }
    }

    for (int i=1;i<=q;i++)
        cout << ans[i] << endl;
    return 0;
}