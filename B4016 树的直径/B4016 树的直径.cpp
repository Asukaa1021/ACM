#include<bits/stdc++.h>
using namespace std;
int n,ans,st;
vector< vector<int> > tr(100005);
vector<bool> vis(100005);

void dfs(int depth,int u,int fa)
{
	if(depth > ans)
	{
		ans = depth;
		st = u;
	}
	for(auto & v : tr[u])
	{
		if(vis[v] || v == fa) continue;
		vis[v] = true;
		dfs(depth + 1,v,u);
		vis[v] = false;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin >> n;
	for(int i = 1;i < n;i++)
	{
		int u,v;
		cin >> u >> v;
		tr[u].push_back(v);
		tr[v].push_back(u);
	}
	dfs(0,1,-1);
	dfs(0,st,-1);
	cout << ans << endl;
}