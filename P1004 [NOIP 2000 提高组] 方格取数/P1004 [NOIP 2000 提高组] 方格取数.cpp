#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<long long>> Map(10,vector<long long> (10));
long long dp[20][10][10];
int main()
{
	cin >> n;
	long long x,y,k;
	
	while(scanf("%lld%lld%lld",&x,&y,&k))
	{
		if(x == 0 && y == 0 && k == 0) break;
		Map[x][y] = k;
	}
	dp[2][1][1] = Map[1][1];
	for(int i = 3;i <= 2 * n;i++)
	{
		for(int x1 = max(1,i - n);x1 <= n && x1 <= i - 1;x1++)
		{
			for(int x2 = x1;x2 <= n && x2 <= i - 1;x2++)
			{
				int y1 = i - x1;
				int y2 = i - x2;
				if(x1 > 1 && y2 > 1)
				{
					dp[i][x1][x2] = max(dp[i][x1][x2],dp[i - 1][x1 - 1][x2]);
				}
				if(x1 > 1 && x2 > 1)
				{
					dp[i][x1][x2] = max(dp[i][x1][x2],dp[i - 1][x1 - 1][x2 - 1]);
				}
				if(y1 > 1 && y2 > 1)
				{
					dp[i][x1][x2] = max(dp[i][x1][x2],dp[i - 1][x1][x2]);
				}
				if(y1 > 1 && x2 > 1)
				{
					dp[i][x1][x2] = max(dp[i][x1][x2],dp[i - 1][x1][x2 - 1]);
				}
				if(x1 == x2) dp[i][x1][x2] += Map[x1][y1];
				else dp[i][x1][x2] += Map[x1][y1] + Map[x2][y2];
			}
		}
	}
	cout << dp[n * 2][n][n] << endl;
}