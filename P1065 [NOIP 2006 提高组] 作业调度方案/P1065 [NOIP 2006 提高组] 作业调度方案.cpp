#include<bits/stdc++.h>
using namespace std;

int n,m;
int order[500];
struct node{
	int id;
	int cost;	
}a[21][21];//n goods  m step


int step[21];//save the step of goods
bool mec[21][10005];
int endTime[21];
int ans=0;
int main()
{	
	cin>>m>>n;
	for(int i=1;i<=n*m;i++)
		cin>>order[i];
		
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j].id;
			
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j].cost;		
			
	for(int i=1;i<=n*m;i++)
	{
		
		int now=order[i];
		step[now]++;
		int k=a[now][step[now]].id;
		int s=0;
		for(int j=endTime[now]+1;;j++)
		{
			if(mec[k][j]==false) s++;
			if(mec[k][j]==true)
			{
				s=0;
				continue;
			}
			if(s==a[now][step[now]].cost)
			{
				endTime[now]=j;
				ans=max(ans,j);
				for(int u=j;u>=j-s+1;u--)
				{
					mec[k][u]=1;
				}
				
				break;
			}
		}
		
	}	
	cout<<ans<<endl;	
	return 0;
}
