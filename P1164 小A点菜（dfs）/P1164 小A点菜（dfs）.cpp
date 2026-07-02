#include<bits/stdc++.h>
using namespace std;
int n,m;
bool visit[105];
int a[105];
int ans=0;

void dfs(int start,int sum)
{
	if(sum>m) return;
	if(sum==m) 
	{
		ans++;
		return;
	}
	for(int i=start;i<=n;i++)
	{
		if(!visit[i])
		{
			visit[i]=1;
			sum+=a[i];
			dfs(i,sum);
			sum-=a[i];
			visit[i]=0;
		} 
	}
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0);
	cout<<ans;
}