#include<bits/stdc++.h>
using namespace std;

int n,m,k;
unordered_map<int, unordered_map<int, unordered_set<int>>> ban;
vector<vector<int>> edge;
int dis[3005][3005];
int _prev[3005][3005];

void Print(int x,int y)
{
	if(_prev[x][y] == 0) return;
	Print(_prev[x][y],x);
	cout << x << " ";
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin >> n >> m >> k;
	edge.resize(n + 1);
	for(int i = 1;i <= m;i++)
	{
		int u,v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for(int i = 0;i < k;i++)
	{
		int u,v,t;
		cin >> u >> v >> t;
		ban[u][v].insert(t);
	}
	memset(dis,0x3f,sizeof dis);
	
	queue<pair<int,pair<int,int>>> pq;
//	for(int i = 1;i <= 3000;i++) dis[i][1] = 0;
	dis[0][1] = 0;
	pq.push({0,{0,1}});
	while(!pq.empty())
	{
		int u = pq.front().second.second;
		int fa = pq.front().second.first;
		pq.pop();
		for(auto v : edge[u])
		{
			if(ban[fa][u].count(v) > 0) continue;
			
			if(dis[u][v] > dis[fa][u] + 1)
			{
				dis[u][v] = dis[fa][u] + 1;
				_prev[u][v] = fa;
				pq.push({dis[u][v],{u,v}});
				if(v == n)
				{	
					int ans = 1;
					for(int i = 2;i <= n;i++)
					{
						if(dis[ans][n] > dis[i][n]) 
							ans = i;
					}
					cout << dis[ans][n] << endl;
					cout << 1 << " ";
					Print(ans,n);
					cout << n << endl;
					return 0;
				}
			}
		}
	}
}
