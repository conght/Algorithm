#include <iostream>

using namespace std;

int a[200001];
int d[200001][200001];
int ans[200001];

int binary_search(int* d, int end, int arrow)
{
    if (end == 1)
    {
        if (d[1] == arrow)
            return 1;
        else
            return -1;
    }

    if (arrow < d[1] || arrow > d[end])
        return -1;

    int start = 1;
    while (start < end)
    {
        int mid = (end - start)/2;
        if (arrow == d[mid])
            return mid;
        if (arrow < d[mid])
            end = mid-1;
        else
            start = mid+1;
    }
    return -1;
}
int main()
{
    int n,q;
    cin >> n >> q;

    for (int i=1;i<=n;i++)
        cin >> a[i];

    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            d[i][j] = d[i][j-1] + a[j];


    int index = 1;
    int left = n;
    for (int i=1;i<=q;i++)
    {
        int arrow = 0;
        cin >> arrow;
        index = binary_search(d[index], n-index+1, arrow);
        if (index == -1 || index == (n-index+1))
        {
            index = 1;
            ans[i] = n;
        }
        else
        {
            index = index + 1;
            left -= index;
            ans[i] = left;
        }
    }

    for (int i=1;i<=q;i++)
        cout << ans[i] << endl;
    return 0;
}