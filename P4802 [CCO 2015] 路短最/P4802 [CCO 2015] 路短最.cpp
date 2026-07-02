#include<bits/stdc++.h>
using namespace std;
int n,m;
int edge[20][20];
int dp[19][1 << 20];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	memset(dp,-0x3f,sizeof dp);
	memset(edge,-0x3f,sizeof edge);
	dp[0][1] = 0;
	for(int i = 1;i <= m;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		edge[a][b] = max(edge[a][b],c);
	}
	for(int k = 1;k < (1 << n);k++)
	{
		for(int i = 0;i < n;i++)
		{
			if((k & (1 << i)) == 0) continue;
			
			for(int j = 0;j < n;j++)
			{
				if(edge[i][j] == -0x3f3f3f3f) continue;
				if(k & (1 << j)) continue;
				int newk = k | (1 << j);
				dp[j][newk] = max(dp[j][newk],dp[i][k] + edge[i][j]);
			}
		}
	}
	int ans = 0;
	for(int k = 1;k < (1 << n);k++)
	{
		if(k & (1 << (n - 1))) ans = max(ans,dp[n - 1][k]);
	}
	cout << ans << endl;
}
