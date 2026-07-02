#include<bits/stdc++.h>
using namespace std;

int dp[300005][3];
int n,k;
int a[300005];
int main()
{
	cin >> n >> k;
	for(int i = 1;i <= n;i++) cin >> a[i];
	dp[0][1] = -INT_MAX + 5;
	dp[0][2] = -INT_MAX + 5;
	dp[0][0] = 0;
	for(int i = 1;i <= n;i++)
	{
		dp[i][0] = max(dp[i - 1][0],max(dp[i - 1][1],dp[i - 1][2]));
		dp[i][1] = max(dp[i - 1][0] - k + a[i],dp[i - 1][2] + a[i]);
		dp[i][2] = dp[i - 1][1];
	}
	cout << max(dp[n][1],max(dp[n][2],dp[n][0])) << endl;
}