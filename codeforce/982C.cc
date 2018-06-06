//http://codeforces.com/contest/982/problem/C

#include <iostream>
#include <algorithm>

using namespace std;

void solution()
{
    int n;
    cin >> n;

    if (n&1)
    {
        cout << "-1" << endl;
        return;
    }

    int ans = 0;

    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    for (int i=0;i<n;i++)
    {
        d[0][i] = a[i];
    }

    for (int i=1;i<n;i++)
    {
        for (int j=0;j<n-i;j++)
        {
            d[i][j] = d[i-1][j]^d[i-1][j+1];
        }
    }

    for (int i=1;i<n;i++)
    {
        for (int j=0;j<n-i;j++)
        {
            d[i][j] = max(d[i][j], max(d[i-1][j], d[i-1][j+1]));
        }
    }

    cin >> q;
    while(q-- > 0)
    {
        cin >> l;
        cin >> r;
        cout << d[r-l][l-1] << endl;
    }

}

int main()
{
    solution();
}