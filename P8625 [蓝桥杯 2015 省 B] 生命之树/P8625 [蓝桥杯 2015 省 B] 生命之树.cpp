#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<int> num;
vector<vector<int>> tr;
int dp[100005];
void dfs(int u,int fa)
{
	if(tr[u].size() == 1 && tr[u][0] == fa)
	{
		dp[u] = num[u];
		return;
	}
	int sum = 0;
	for(auto & v : tr[u])
	{
		if(fa == v) continue;
		dfs(v,u);
		if(dp[v] > 0) sum += dp[v];
	}
	dp[u] = sum + num[u];
}

signed main()
{
	cin >> n;
	num.resize(n + 1);
	tr.resize(n + 1);
	for(int i = 1;i <= n;i++) cin >> num[i];
	for(int i = 1;i < n;i++)
	{
		int u,v;
		cin >> u >> v;
		tr[u].push_back(v);
		tr[v].push_back(u);
	}
	dfs(1,-1);int Max = 0;
	for(int i = 1;i <= n;i++)
	{
		Max = max(dp[i],Max);
	}
	cout << Max << endl;
}
