#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > tr;
vector< vector<int> > fa;
vector<int> dep;

void dfs(int u,int father)
{
	dep[u] = dep[father] + 1;
	fa[u][0] = father;
	for(int i = 1;i <= 10;i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	
	for(auto & v : tr[u])
	{
		if(v == father) continue;
		dfs(v,u);
	}
}

int lca(int u,int v)
{
	if(dep[u] < dep[v]) swap(u,v);
	for(int i = 10;i >= 0;i--)
	{
		if(dep[fa[u][i]] >= dep[v]) u = fa[u][i];
	}
	if(u == v) return v;
	for(int i = 10;i >= 0;i--)
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
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	for(int i = 1;i <= t;i++)
	{
		int n;
		cin >> n;
		tr.resize(n + 1);
		fa.clear();
		fa.resize(n + 1,vector<int> (11));
		dep.clear();
		dep.resize(n + 1);
		for(int u = 1;u <= n;u++)
		{
			int num;
			cin >> num;
			for(int k = 1;k <= num;k++)
			{
				int v;
				cin >> v;
				tr[u].push_back(v);
				tr[v].push_back(u);
			}
		}
		dfs(1,1);
		int q;
		cin >> q;
		cout << "Case "<< i << ":" << endl;
		while(q--)
		{
			int v,u;
			cin >> u >> v;
			cout << lca(u,v) << endl;
		}
	}
}
