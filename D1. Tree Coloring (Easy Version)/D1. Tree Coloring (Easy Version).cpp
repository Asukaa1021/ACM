#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<vector<int>> tr(n + 1);
	for(int i = 1;i < n;i++)
	{
		int u,v;
		cin >> u >> v;
		tr[u].push_back(v);
		tr[v].push_back(u);
	}
	queue<pair<int,int>> q;
	vector<int> dep(n + 1),dep_cnt(n + 1);
	q.push({-1,1});
	dep[1] = 1;
	vector<int> sameFa(n + 1);
	while(q.size())
	{
		int fa = q.front().first;
		int u = q.front().second;
		q.pop();
		
		for(auto &v : tr[u])
		{
			if(v == fa) continue;
			dep[v] = dep[u] + 1;
			if(sameFa[dep[v]] == 0) sameFa[dep[v]] = u;
			else
			{
				if(sameFa[dep[v]] != u) sameFa[dep[v]] = -1;
			}
			q.push({u,v});
		}
	}
	for(int i = 0;i <= n;i++)
	{
		if(dep[i] > 0) dep_cnt[dep[i]]++;
	}
	int maxn = 0;
	for(int i = 1;i <= n;i++) 
	{
		maxn = max(maxn,dep_cnt[i]);
		if(sameFa[i] != -1 && sameFa[i] != 0) maxn = max(maxn,dep_cnt[i] + 1);
	}
	cout << maxn << '\n';
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}