#include<bits/stdc++.h>
using namespace std;
int n,m;
int fa[200005];
int dis[200005];
vector<vector<pair<int,int>>> e;
int find(int x)
{
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

void unite(int x,int y)
{
	int fax = find(x);
	int fay = find(y);
	if(fax == fay) return;
	fa[fax] = fay;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	memset(dis,0x3f,sizeof dis);
	e.resize(n + 1);
	for(int i = 1;i <= n;i++) fa[i] = i;
	for(int i = 1;i <= m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		unite(u,v);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	int f = find(1);
	for(int i = 1;i <= n;i++)
	{
		if(find(i) != f) 
		{
			cout << -1 << endl;
			return 0;
		}
	}
	queue<int> q;
	q.push(1);
	dis[1] = 0;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(auto [v,w] : e[u])
		{
			int dd = max(dis[u],w);
			if(dd >= dis[v]) continue;
			dis[v] = dd;
			q.push(v);
		}
	}
	int Max = 0;
	for(int i = 1;i <= n;i++)
	{
		Max = max(Max,dis[i]);
	}
	cout << Max << endl;
}
