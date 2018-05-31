#include <iostream>
#include <vector>


using namespace std;

long long d[51][51];

long long mysum(std::vector<long long>& a, int start, int end)
{
    long long ans = 0;
    for (int i=start;i<=end;i++)
        ans += a[i];
    return ans;
}

void solution()
{
    int n,k;
    cin >> n;
    cin >>k;

    std::vector<long long> a(n+1);

    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }

    d[1][0] = a[1];

    for (int i=1;i<=n;i++)
        d[i][0] = mysum(a, 1, i);

    for (int i=2;i<=n;i++)
    {

        for(int j=1;j<i;j++)
        {
            for (int m=0;m<k-1 && m<=j-1;m++)
            {
                //d[i][m] = 0;
                long long temp = d[j][m] & mysum(a, j+1,i);
                if (temp > d[i][m+1])
                    d[i][m+1] = temp;
            }
        }
    }
    
    for (int i=1;i<=n;i++) 
    {
        for(int j=0;j<=k;j++)
            cout << d[i][j] << " ";
        cout << endl; 
    }

}

int main()
{
    solution();
}