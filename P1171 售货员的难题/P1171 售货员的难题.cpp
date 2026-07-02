#include<bits/stdc++.h>
using namespace std;

int n;
int dis[25][25];
int dp[25][2000000];
int main()
{
	int ans=INT_MAX;
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		cin>>dis[i][j];
	memset(dp,127,sizeof dp);
	for(int i=2;i<=n;i++)
	dp[i][1+(1<<i-1)]=dis[1][i];
	for(int k=1;k<=(1<<n)-1;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if((k&(1<<i-1))==0) continue;
			for(int j=1;j<=n;j++)
			{
				if(i==j) continue;
				if((k&(1<<j-1))==0) continue;
				dp[i][k]=min(dp[i][k],dp[j][k-(1<<i-1)]+dis[j][i]);
			}
		}
	}	
	for(int i=1;i<=n;i++)
	{
		dp[i][(1<<n)-1]+=dis[i][1];
		ans=min(ans,dp[i][(1<<n)-1]);
	}
	cout<<ans<<endl;
	
}