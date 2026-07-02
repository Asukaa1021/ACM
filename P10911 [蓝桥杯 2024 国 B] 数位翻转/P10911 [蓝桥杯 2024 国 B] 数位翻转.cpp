#include<bits/stdc++.h>
#define int long long 
#define lp p << 1
#define rp p << 1 | 1
using namespace std;
int dp[1005][1005][2];
int rev(int k)
{
	vector<int> num;
	while(k > 0)
	{
		num.push_back(k % 2);
		k /= 2;
	}
	int revk = 0;
	for(int i = 0;i < num.size();i++)
	{
		revk <<= 1;
		revk += num[i];
	}
	return revk;
}
int n,m,sum;
vector<int> a,d;

signed main()
{
	cin >> n >> m;
	a.resize(n + 1);
	d.resize(n + 1);
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		sum += a[i];
		d[i] = rev(a[i]) - a[i];
//		cout << d[i] << endl;
	}
	for(int i = 1;i <= n;i++)
	{
		for(int k = 1;k <= m;k++)
		{
			dp[i][k][1] = max(dp[i - 1][k - 1][0],dp[i - 1][k][1]) + d[i];
			dp[i][k][0] = max(dp[i - 1][k][1],dp[i - 1][k][0]);
		}
	}
	int Max = 0;
	for(int i = 0;i <= m;i++) 
	{
		Max = max({Max,dp[n][i][0],dp[n][i][1]});
	}
	sum += Max;
//	cout << Max << endl;
	cout << sum << endl;
}