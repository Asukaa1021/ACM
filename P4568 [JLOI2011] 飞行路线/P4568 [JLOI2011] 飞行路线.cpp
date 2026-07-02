#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,k,s,t;
	cin >> n >> m >> k;
	cin >> s >> t;
	t += n * k;
	vector<vector<pair<long long,int>>> edge(n * (k + 2));
	vector<long long> dis(n * (k + 2),INT_MAX);
	for(int i = 1;i <= m;i++)
	{
		int a,b;
		int c;
		scanf("%d%d%d",&a,&b,&c);
		for(int j = 0;j <= k;j++)
		{
			edge[a + n * j].push_back({c,b + n * j});
			edge[b + n * j].push_back({c,a + n * j});
			if(j != k)
			{
				edge[a + n * j].push_back({0,b + n * (j + 1)});
				edge[b + n * j].push_back({0,a + n * (j + 1)});	
			}
		}
	}
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
	dis[s] = 0;
	pq.push({0,s});
	
	while(!pq.empty())
	{
		long long Dis = pq.top().first;
		int u = pq.top().second;
		pq.pop();
		if(Dis > dis[u]) continue;
		
		for(auto &i : edge[u])
		{
			int v = i.second;
			long long w = i.first;	
			if(dis[v] > dis[u] + w)
			{
				dis[v] = dis[u] + w;
				if((t - v) % n == 0 && dis[v] == 0)//可能不需要k次免费就能到达   特判
				{
					cout << 0 << endl;
					return 0;
				}
				pq.push({dis[v],v});	
			}	
		}
	}
	cout << dis[t] << endl;
}