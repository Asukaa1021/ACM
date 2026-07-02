#include<bits/stdc++.h>
using namespace std;

int n;
int edge[25][25];
int dp[21][(1 << 20)];
int main()
{
	cin >> n;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			cin >> edge[i][j];
	
	
	memset(dp,0x3f,sizeof dp);
	dp[0][1] = 0;
	for(int k = 1;k < (1 << n);k++)
	{
		for(int i = 0;i < n;i++)
		{
			if((k & (1 << i)) == 0) continue;
			for(int j = 0;j < n;j++)
			{
				if(k & (1 << j)) continue;
				int newk = k | (1 << j);
				dp[j][newk] = min(dp[j][newk],dp[i][k] + edge[i][j]);
			}
		}
	}
	cout << dp[n - 1][(1 << n) - 1] << endl;
	
}
