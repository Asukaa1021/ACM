#include<bits/stdc++.h>
using namespace std;

int ans[21][21][21];

int main()
{
	long long a=0,b=0,c=0;
	for(int i=0;i<=20;i++)
	{
		for(int j=0;j<=20;j++)
		{
			for(int u=0;u<=20;u++)
			{
				if(i==0||j==0||u==0) ans[i][j][u]=1;
				else if(i<j&&j<u) ans[i][j][u]=ans[i][j][u-1]+ans[i][j-1][u-1]-ans[i][j-1][u];
				else ans[i][j][u]=ans[i-1][j][u]+ans[i-1][j-1][u]+ans[i-1][j][u-1]-ans[i-1][j-1][u-1];
			}
		}
	}
	
	while(a!=-1||b!=-1||c!=-1)
	{
		cin>>a>>b>>c;
		if(a!=-1||b!=-1||c!=-1)
		{
			if(a<=0||b<=0||c<=0) //在第二步前面因为第二步包含第一步
			printf("w(%lld, %lld, %lld) = %d\n",a,b,c,1);
			else if(a>20||b>20||c>20) 
			printf("w(%lld, %lld, %lld) = %d\n",a,b,c,ans[20][20][20]);
			else 
			printf("w(%lld, %lld, %lld) = %d\n",a,b,c,ans[a][b][c]);
		}
	}
	
}