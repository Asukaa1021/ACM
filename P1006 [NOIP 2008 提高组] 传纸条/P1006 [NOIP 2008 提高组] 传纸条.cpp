#include<bits/stdc++.h>
using namespace std;

int n,m;
int dp[105][55][55];

int main()
{
	cin >> m >> n;
	vector<vector<int>> stu(m + 200,vector<int> (n + 200));
	for(int i = 1;i <= m;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			cin >> stu[i][j];
		}
	}
	dp[3][1][2] = stu[1][2] + stu[2][1];
	for(int i = 4;i <= n + m - 1;i++)
	{
		for(int x1 = 1;(x1 <= i - 1)&&(x1 <= n - 1);x1++)
		{
			for(int x2 = x1 + 1;(x2 <= i - 1)&&(x2 <= n);x2++)
			{
				if(x1 > 1)
				{
					dp[i][x1][x2] = max(dp[i][x1][x2],dp[i-1][x1-1][x2-1]);
				}
				if(i - x2 > 1)//y2 > 1
				{
					dp[i][x1][x2] = max(dp[i][x1][x2],dp[i-1][x1][x2]);
				}
				if(x1 > 1 && i - x2 > 1)
				{
					dp[i][x1][x2] = max(dp[i][x1][x2],dp[i-1][x1-1][x2]);
				}
				dp[i][x1][x2] = max(dp[i][x1][x2],dp[i-1][x1][x2-1]);
				dp[i][x1][x2] += stu[i-x1][x1] + stu[i-x2][x2];
			}
		}
	}
	cout << dp[n + m - 1][n-1][n] << endl;
}