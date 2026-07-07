#include<bits/stdc++.h>
#define int long long
using namespace std;

int a[3005];

int dp[3005][3005];

signed main()
{
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 0;i <= n;i++)
	{
		for(int j = 0;j <= n;j++) dp[i][j] = -0x3f3f3f3f3f3f3f3f;
 	}
	for(int i = 0;i <= 3000;i++) dp[1][i] = a[1];
	
	for(int pos = 2;pos <= n;pos++)
	{
		for(int k = 1;k < pos;k++) 
		{
			if(pos - k > k || pos - k == 1) dp[pos][k] = dp[pos - k][k] + a[pos];
			/*if(pos == 4)
			{
				cout << k << " : " << dp[pos][k] << '\n';
				cout << dp[pos - k][k] << '\n';
				cout << dp[pos][k] << '\n';
			}*/
		}
		
		for(int k = pos - 1;k >= 1;k--)
		{
			dp[pos][k] = max(dp[pos][k],dp[pos][k + 1]);
			/*if(pos == 4)
			{
				cout << k << " : " << dp[pos][k] << '\n';
				cout << dp[pos][k] << " " << dp[pos][k + 1] << '\n';
			}*/
		}
	}
	//cout << dp[4][3] << '\n';
	//cout << dp[1][1] << " " << a[4] << '\n';
	cout << dp[n][1] << '\n';
}
