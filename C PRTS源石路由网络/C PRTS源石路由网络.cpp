#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int modd = 998244353;
vector<vector<pair<int,int>>> e;
vector<int> c,sz;
vector<vector<int>> dp;
int n,m;
void dfs(int u)
{
	int cur_num = min(m,c[u]);
	for(int i = 0;i <= cur_num;i++) dp[u][i] = 1;
	for(int i = c[u] + 1;i <= m;i++) dp[u][i] = 0;
	sz[u] = cur_num;
	if(e[u].size() == 0) return;
	
	for(auto &[v,w] : e[u])
	{
		dfs(v);
		int v_num = min({sz[v],w,m});
		int next_num = min(v_num + sz[u],m);
		vector<int> temp(next_num + 1);
		for(int i = 0;i <= sz[u];i++)
		{
			for(int j = 0;j <= v_num;j++)
			{
				if(!dp[u][i]) break;
				if(i + j > next_num) break;
				temp[i + j] = (temp[i + j] + dp[u][i] * dp[v][j] % modd) % modd;
			}
		}
		for(int i = 0;i <= next_num;i++) dp[u][i] = temp[i];
		sz[u] = next_num;
	}
}

void solve()
{
	cin >> n >> m;
	c.clear();
	c.resize(n + 1);
	sz.clear();
	sz.resize(n + 1);
	e.clear();
	e.resize(n + 1);
	dp.clear();
	dp.resize(n + 1,vector<int> (m + 1));
	for(int i = 1;i <= n;i++) cin >> c[i];
	for(int i = 1;i <= n - 1;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		e[u].push_back({v,w});
	}
	dfs(1);
	cout << dp[1][m] << '\n';
}


signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int t;
	cin >> t;
	while(t--) solve();
}