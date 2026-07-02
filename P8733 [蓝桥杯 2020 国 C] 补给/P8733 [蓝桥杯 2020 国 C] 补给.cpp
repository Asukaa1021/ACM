#include<bits/stdc++.h>
using namespace std;

struct p
{
	double x,y;
}point[22];
double dp[1 << 20][22];
vector< vector<double> > edge(22, vector<double> (22));

int main()
{
	int n;
	double D;
	cin >> n >> D;
	for(int i = 1;i <= n;i++)
	{
		double x,y;
		cin >> x >> y;
		point[i].x = x;
		point[i].y = y;
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = i + 1;j <= n;j++)
		{
			edge[i][j] = sqrt((point[i].x - point[j].x) * (point[i].x - point[j].x) + (point[i].y - point[j].y) * (point[i].y - point[j].y)) ;
			if(edge[i][j] <= D) edge[j][i] = edge[i][j];
			else
			{
				edge[i][j] = DBL_MAX;
				edge[j][i] = DBL_MAX;
			}
		}
		edge[i][i] = 0;
	}
	for(int k = 1;k <= n;k++)
	{
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= n;j++)
			{
				edge[i][j] = min(edge[i][k] + edge[k][j],edge[i][j]);
			}
		}
	}

	for(int i = 0;i < (1 << 20);i++)
	{
		for(int j = 0;j < 22;j++)
		{
			dp[i][j] = DBL_MAX;
		}
	}
	for(int i = 2;i <= n;i++)
	{
		dp[1 + (1 << (i - 1))][i] = edge[1][i];
	}
	for(int k = 2;k < (1 << n);k++)
	{
		for(int i = 1;i <= n;i++)
		{
			if(((1 << (i - 1)) & k) == 0) continue;
			for(int j = 1;j <= n;j++)
			{
				if(((1 << (j - 1)) & k) == 0 || i == j) continue;
				dp[k][i] = min(dp[k][i],dp[k - (1 << i - 1)][j] + edge[i][j]);
			}
		}
	}
	double ans = 0x3f3f3f3f;
	for(int i = 1;i <= n;i++)
	{
		ans = min(ans,dp[(1 << n) - 1][i] + edge[1][i]);
	}
	printf("%.2lf\n",ans);
}