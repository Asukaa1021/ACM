#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,s;
	cin >> n >> m >> s;
	vector<vector<pair<long long,int>>> edges(n + 2);
	for(int i = 1;i <= m;i++)
	{
		int v,u,w;
		cin >> u >> v >> w;
		edges[u].push_back({w,v});
	}
	vector<long long> dis(n + 3,INT_MAX);
	
	dis[s] = 0;
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
	pq.push({0,s});
	
	while(!pq.empty())
	{
		long long Dis = pq.top().first;
		int u = pq.top().second;
		pq.pop();
		if(Dis > dis[u]) continue;
		
		for(int i = 0;i < edges[u].size();i++)
		{
			int W = edges[u][i].first;
			int V = edges[u][i].second;
			
			if(dis[V] > dis[u] + W)
			{
				dis[V] = dis[u] + W;
				pq.push({dis[V],V});
			} 
		}
	}
	
	for(int i = 1;i <= n;i++) cout << dis[i] << " " ;
}