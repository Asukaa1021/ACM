#include<bits/stdc++.h>
using namespace std;

int n;
double x[20],y[20];
double dis[20][20];
double dp[20][50000];

int main()
{
	double ans=DBL_MAX;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>x[i]>>y[i];
	memset(dp,127,sizeof dp);
	for(int i=0;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		dis[i][j]=dis[j][i]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
		
	for(int i=1;i<=n;i++)
		dp[i][1<<i-1]=dis[0][i];
		
	for(int k=1;k<(1<<n);k++)
	{
		for(int i=1;i<=n;i++)
		{
			if((k&(1<<i-1))==0) continue;// == 优先级高于 &  要打括号
			for(int j=1;j<=n;j++)
			{
				if((k&(1<<j-1))==0) continue;
				if(i==j) continue;
				dp[i][k]=min(dp[i][k],dp[j][k-(1<<i-1)]+dis[i][j]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	ans=min(ans,dp[i][(1<<n)-1]);
	
	printf("%.2lf",ans);
}