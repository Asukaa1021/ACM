#include<bits/stdc++.h>
using namespace std;
int n,k,x,y;
vector<int> a[200005];
bool key[200005];
int dis[200005];
int keynum[200005];
long long valuemin,minCount;

void bfs1(int u,int p,int depth)
{
	keynum[u]=key[u];
	if(key[u]==1) dis[1]+=depth;
	for(int i=0;i<a[u].size();i++)
	{
		if(a[u][i]==p) continue;
		bfs1(a[u][i],u,depth+1);
		keynum[u]+=keynum[a[u][i]];
	}
}

void bfs2(int u,int p)
{
	if(dis[u]<valuemin)
	{
		valuemin=dis[u];
		minCount=1;
	}
	else if(valuemin==dis[u]) minCount++;
	for(int i=0;i<a[u].size();i++)
	{
		if(a[u][i]==p) continue;
		dis[a[u][i]]=dis[u]+k-2*keynum[a[u][i]];
		bfs2(a[u][i],u);
	}
}

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++) 
	{
		scanf("%d",&x);
		key[x]=1;
	}
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d%d",&x,&y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	bfs1(1,-1,0);
	valuemin=dis[1];
	minCount=0;
	bfs2(1,-1);
	
	printf("%d %d",valuemin,minCount);
}