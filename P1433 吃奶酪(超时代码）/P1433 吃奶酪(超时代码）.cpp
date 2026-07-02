#include<bits/stdc++.h>
using namespace std;

double x[20],y[20];
double dis[20][20];
bool chosed[20];
double s=100000000;
int n;

void dfs(int start,int depth,double sumdis)
{
	if(sumdis>=s) return ;//剪枝
	if(depth==n)
	{
		s=min(s,sumdis);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(chosed[i]) continue;
		chosed[i]=1;
		sumdis+=dis[start][i];
		dfs(i,depth+1,sumdis);
		sumdis-=dis[start][i];
		chosed[i]=0;
	}
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
	}
	for(int i=0;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			dis[i][j]=dis[j][i]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
		}
		
	dfs(0,0,0);	
	
	printf("%.2f",s);
}