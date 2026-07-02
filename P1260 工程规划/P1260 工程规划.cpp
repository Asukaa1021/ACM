#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
struct Edge
{
	int u,v,w;
};
vector<Edge> e;
signed main()
{
	cin >> n >> m;
	for(int i = 1;i <= m;i++)
	{
		int u,v,w;
		cin >> v >> u >> w;
		e.push_back({u,v,w});
	}
	int Min = INT_MAX;
	vector<int> dis(n + 1,INT_MAX);
	for(int i = 1;i < n;i++)
	{
		for(int j = 0;j < m;j++)
		{
			auto [u,v,w] = e[j];
			if(dis[v] > dis[u] + w)
			{
				dis[v] = dis[u] + w;
				Min = min(dis[v],Min);
			}
		}
	}
	Min = -Min;
	bool flg = false;
	for(int j = 0;j < m;j++)
	{
		auto [u,v,w] = e[j];
		if(dis[v] > dis[u] + w)
		{
			flg = true;
			break;
		}
	}
	for(int i = 1;i <= n;i++)
		if(dis[i] + Min > INT_MAX / 2) 
			flg = true;
			
	if(flg)	cout << "NO SOLUTION" << endl;
	else 
	{
		for(int i = 1;i <= n;i++)
			cout << dis[i] + Min << endl;
	}
}
