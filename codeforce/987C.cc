#include <iostream>

long long s[3001] = {0};
long long c[3001] = {0};

long long d[3001][4];

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i=1;i<n+1;i++)
	{
		cin>>s[i];
	}
	for (int i=1;i<n+1;i++)
	{
		cin>>c[i];
	}

	d[1][1] = c[1];
	d[1][2] = 300000001;
	d[1][3] = 300000001;

	long long ans = 300000001;
	bool flag = false;
	for(int i=2;i<=n;i++)
	{
		d[i][1] = c[i];
		d[i][2] = 300000001;
		d[i][3] = 300000001;
		for(int j=1;j<i;j++)
		{
			if (s[i]>s[j])
			{
				 d[i][2] = min(d[i][2], min(d[j][2], d[j][1] + c[i]));
				 d[i][3] = min(d[i][3], d[j][2]+c[i]);
				 if (ans > d[i][3])
				 {
				 	flag = true;
				 	ans = d[i][3];
				 }
			}
		}
	}
	if (flag)
		cout << ans << endl;
	else 
		cout << -1 << endl;
}