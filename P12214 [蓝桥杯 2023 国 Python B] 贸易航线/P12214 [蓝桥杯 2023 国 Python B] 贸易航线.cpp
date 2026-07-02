#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
vector<vector<int>> goods;
int dp[100005][15];//经过第k个城市时，拥有q的商品时的利润
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin >> n >> m >> k;
	goods.resize(n + 1,vector<int> (m + 1));
	
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			cin >> goods[i][j];
			
	for(int i = n;i >= 1;i--)
	{
		dp[i][0] = dp[i + 1][0];
		for(int j = 1;j <= m;j++)
		{
			if(goods[i][j] != -1)
			{
				dp[i][0] = max(dp[i][0],dp[i + 1][j] - goods[i][j]);
			}
		}
		for(int j = 1;j <= m;j++)
		{
			dp[i][j] = dp[i + 1][j];
			if(goods[i][j] != -1)
			{
				dp[i][j] = max(dp[i][j],dp[i][0] + goods[i][j]);
			}
		}
	}
	cout << dp[1][0] * k << endl;
}