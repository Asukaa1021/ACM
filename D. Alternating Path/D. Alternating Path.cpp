#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n,m;
	cin >> n >> m;
	vector<vector<int>> e;
	vector<bool> vis(n + 1);
	e.resize(n + 1);
	vector<int> f(n + 1);
	for(int i = 1;i <= m;i++)
	{
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	int ans = 0;
	for(int i = 1;i <= n;i++)
	{
		if(vis[i]) continue;
		queue<pair<int,int>> q;
		bool flg = true;
		int point_num = 0;
		int beauti_num = 0;
		int maxn = 0;
		
		f[i] = 1;
		vis[i] = true;
		q.push({-1,i});
		
		while(!q.empty())
		{
			int fa = q.front().first;
			int u = q.front().second;
			q.pop();
			point_num++;
			if(f[u] == 1) beauti_num++;
			for(auto & v : e[u])
			{
				if(v == fa) continue;
				if(vis[v])
				{
					if(f[u] * (-1) != f[v]) flg = false;
					continue;
				}
				f[v] = f[u] * (-1);
				vis[v] = true;
				q.push({u,v});
			}
		}
		if(flg) maxn = max(beauti_num,point_num - beauti_num);
		ans += maxn;
	}
	cout << ans << '\n';
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int t;
	cin >> t;
	while(t--) solve();
}