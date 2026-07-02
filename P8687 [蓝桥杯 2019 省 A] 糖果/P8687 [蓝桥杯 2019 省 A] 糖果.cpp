#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<int> tg;
vector<int> dp(1 << 23,0x3f3f3f3f);
int main()
{
	cin >> n >> m >> k;
	tg.resize(105);
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= k;j++)
		{
			int t;
			cin >> t;
			tg[i] = (tg[i] | (1 << (t - 1)));
		//	dp[tg[i]] = 1;
		}
	}
	dp[0] = 0;
	for(int i = 0;i <= (1 << m) - 1;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			dp[i | tg[j]] = min(dp[i] + 1,dp[i | tg[j]]);
		}
	}
	if(dp[(1 << m) - 1] == 0x3f3f3f3f) cout << -1 << endl;
	else cout << dp[(1 << m) - 1] << endl;
}