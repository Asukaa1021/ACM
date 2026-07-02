#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[10][105];
int n,k;

void solve()
{
	cin >> n >> k;
	int s = 0;
	for(int i = 1;i <= k;i++) s += dp[n][i];
	cout << s << endl;
}

signed main()
{
	for(int i = 0;i <= 9;i++) dp[1][i] = 1;
	for(int i = 2;i <= 7;i++)
	{
		for(int d = 0;d <= 9;d++)
		{
			for(int sum = 0;sum <= 100;sum++)
			{
				if(d <= sum) dp[i][sum] += dp[i - 1][sum - d];
			}
		}
	}
	int t;
	cin >> t;
	while(t--) solve();
}