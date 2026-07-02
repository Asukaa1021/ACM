#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,k;
const int modd = 123456;
int dp[505][505];
signed main()
{
	cin >> n >> k;
	dp[1][0] = 1;
	for(int i = 2;i <= n;i++)
	{
		dp[i][0] = 2;
		for(int j = 0;j <= k;j++)
		{
			dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * (j + 1))% modd;
			dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j] * 2) % modd;
			dp[i + 1][j + 2] = (dp[i + 1][j + 2] + dp[i][j] * (i - j - 2)) % modd;
		}
	}
	
	cout << dp[n][k - 1] << endl;
}
