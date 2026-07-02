#include<bits/stdc++.h>
using namespace std;

int a[1005][1005];
long long up[1005][1005];//不开long long 过不了   司马题目
long long down[1005][1005];
long long dp[1005][1005];
/*
状态转移方程
up[i][j]=max(up[i+1][j],dp[i][j-1])+dp[i][j];
down[i][j]=max(down[i-1][j],dp[i][j-1])+dp[i][j];
dp[i][j]=max(up[i][j],down[i][j]);


*/
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
		
	dp[1][1]=a[1][1];
	for(int i=2;i<=n;i++)
	{
		dp[i][1]=dp[i-1][1]+a[i][1];
	}
	
	for(int j=2;j<m;j++)
	{
		down[1][j]=dp[1][j-1]+a[1][j];
		for(int i=2;i<=n;i++)
		{
			down[i][j]=max(dp[i][j-1],down[i-1][j])+a[i][j];
		}
		up[n][j]=dp[n][j-1]+a[n][j];
		for(int i=n-1;i>=1;i--)
		{
			up[i][j]=max(dp[i][j-1],up[i+1][j])+a[i][j];
		}
		for(int i=1;i<=n;i++)
		{
			dp[i][j]=max(up[i][j],down[i][j]);
		}
	}
	
	dp[1][m]=dp[1][m-1]+a[1][m];
	
	for(int i=2;i<=n;i++)
	{
		dp[i][m]=max(dp[i-1][m],dp[i][m-1])+a[i][m];
	}
	cout<<dp[n][m]<<endl;

	return 0;
}