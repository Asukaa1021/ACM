#include<bits/stdc++.h>
using namespace std;
int n,m,s;
const int N = 5 * 1e5 + 5;
vector<vector<int>> e(N);
int fa[N][20];
vector<int> dep(N);
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
		if(v != father) dfs(v,u);
	}
}

int lca(int u,int v)
{
	if(dep[u] < dep[v]) swap(v,u);
	for(int i = 19;i >= 0;i--)
	{
		if(dep[fa[u][i]] >= dep[v]) u = fa[u][i];
	}//先跳到同一层
	if(v == u) return v;
	for(int i = 19;i >= 0;i--)
	{
		if(fa[u][i] != fa[v][i])
		{
			u = fa[u][i];
			v = fa[v][i];
		}
	}//共同向上跳
	return fa[u][0];
}

int main()
{
	cin >> n >> m >> s;
	for(int i = 1;i < n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(s,0);
	while(m--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		printf("%d\n",lca(u,v));
	}
}