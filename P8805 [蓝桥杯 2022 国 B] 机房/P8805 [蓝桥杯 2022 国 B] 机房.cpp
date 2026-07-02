#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long Time[N];
vector< vector<int> > e(N);
int fa[N][20];
long long preSum[N];
int dep[N];
void dfs(int u,int father)
{
	dep[u] = dep[father] + 1;
	fa[u][0] = father;
	for(int i = 1;i <= 19;i++)
	{
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	}
	for(auto & v : e[u])
	{
		if(v != father)	dfs(v,u);
	}
}

int lca(int v,int u)
{
	if(dep[u] < dep[v]) swap(v,u);
	
	for(int i = 19;i >= 0;i--)
	{
		if(dep[fa[u][i]] >= dep[v]) u = fa[u][i];
	}
	if(v == u) return v;
	for(int i = 19;i >= 0;i--)
	{
		if(fa[u][i] != fa[v][i])
		{
			u = fa[u][i];
			v = fa[v][i];
		}
	}
	return fa[u][0];
}

int main()
{
	int n,m;
	cin >> n >> m;
	for(int i = 1;i < n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		Time[u]++;
		Time[v]++;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	queue<int> q;
	q.push(1);
	dfs(1,0);
	preSum[1] = Time[1];
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(auto & v : e[u])
		{
			if(v == fa[u][0]) continue;
			preSum[v] = preSum[u] + Time[v];
			q.push(v);
		}
	}

	while(m--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		if(u == v) printf("%lld\n",Time[v]);
		else
		{
			int f = lca(u,v);
			
			long long t = preSum[u] + preSum[v] - 2 * preSum[f] + Time[f];
			printf("%lld\n",t);
		}
	}
	
}