//http://codeforces.com/contest/983/submission/38313655

#include <iostream>

using namespace std;

int a[5000] = {0};
int d[5000][5000];

void solution()
{
    int n,q,l,r;
    cin >> n;

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

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }

}

int main()
{
    solution();
}