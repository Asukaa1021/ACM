#include<bits/stdc++.h>
using namespace std;

int n,m;
long long g[1005][1005];
bool vis[1005][1005];
long long ptime[1005];
int main()
{
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> ptime[i];
	}
	vector<vector<int>> edge(n + 1);
	vector<long long> dis(n + 1,LONG_MAX);
	for(int i = 1;i <= m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		g[u][v] = w + ptime[v];
		g[v][u] = w + ptime[u];
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	queue<int> q;
	dis[1] = 0;
	q.push(1);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(auto & v : edge[u])
		{
			if(dis[v] > dis[u] + g[u][v])
			{
				dis[v] = dis[u] + g[u][v];
				if(v == n) continue;
				q.push(v);
			}
		}
	}
	cout << dis[n] - ptime[n] << endl;
}